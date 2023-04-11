#define red 3
#define blue 5
#define green 6
//const int lm35_pin = A0;
int temp_adc;
int temp;
int redValue = 0;
int blueValue = 0;
int greenValue = 0;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  //proba komentar

  Serial.begin(9600);
  pinMode(A0, INPUT);

  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
}

void loop() {

  //za IRL temp sensor (lm35)
  temp_adc = analogRead(A0);
  temp = (temp_adc*(5000/1024))/10;

  //za Tinkercad temp sensor (tmp36)
  //temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

  int minTemp = 20;
  int maxTemp = 30;

  if (temp < minTemp){
    if (redValue > 0){
      redValue -= 1;
    }
    if (greenValue > 0){
      greenValue -= 1;
    }
    if(blueValue < 255){
      blueValue += 1;
    }

    analogWrite(red,redValue);
    analogWrite(blue, blueValue);
    analogWrite(green,greenValue);
  }
  else if (temp > maxTemp){
    if (blueValue > 0){
      blueValue -= 1;
    }
    if (greenValue > 0){
      greenValue -= 1;
    }
    if(redValue < 255){
      redValue += 1;
    }

    analogWrite(red,redValue);
    analogWrite(blue, blueValue);
    analogWrite(green,greenValue);
  }
  else{
    if (redValue > 0){
      redValue -= 1;
    }
    if (blueValue > 0){
      blueValue -= 1;
    }
    if(greenValue < 255){
      greenValue += 1;
    }

    analogWrite(red,redValue);
    analogWrite(blue, blueValue);
    analogWrite(green,greenValue);
  }
  
  Serial.print("temp: ");
  Serial.println(temp);
  
  delay(50);
}
