const int vibrator = 2;
int LED = 7;
int photo = 0;
int buzzer =11;

void setup() {
  pinMode(vibrator,OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(photo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
   int Brightness = analogRead(photo);
   int beat = map(Brightness, 400,1023,10,600);
   int off = map(Brightness, 955,1000,1000,600);
    int buzzerTone = map(Brightness, 1020,200,1100,100);
   Serial.println(analogRead(photo));
   if (Brightness > 300){
     tone(buzzer,buzzerTone);
//    Serial.println("tone:"+buzzerTone);
     digitalWrite(vibrator, HIGH);
     digitalWrite(LED, HIGH);
     delay(beat);
     digitalWrite(vibrator, LOW); 
     digitalWrite(LED, LOW);
     delay(1500);
    } else {
      digitalWrite(vibrator, LOW); 
      digitalWrite(LED, LOW);
      delay(1500);
      noTone(buzzer);
      }

}
