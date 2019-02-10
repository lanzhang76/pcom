int sensorPin = 0;
//int vibrater;
int LED = 13;
int threshold = 950;
int brightnesslevel;
int buzzer =12;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  int brightnesslevel = analogRead(sensorPin);
//  Serial.println(brightnesslevel);
}

void loop() {
//  Serial.println(analogRead(sensorPin));
  int brightRead = analogRead(sensorPin);
//  println(brightnesslevel - brightRead);
  if (brightRead <= threshold && brightRead >900){
    digitalWrite(LED,HIGH);
    tone(buzzer,1000);
    } else if (brightRead <= 900 && brightRead >880){
      tone(buzzer,800);
      } else if (brightRead <= 880 && brightRead >860){
      tone(buzzer,600);
      } else if (brightRead <= 860 && brightRead >840){
      tone(buzzer,500);
      } else {
      digitalWrite(LED,LOW);
      noTone(buzzer);
//      tone(buzzer,900);
    }
    Serial.println(brightRead);
  delay(300);

}
