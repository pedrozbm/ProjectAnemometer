int pinoLed = 13;
int PinoSensor = 15;

void setup() {
PinMode(PinoSensor, INPUT);
PinMode(pinoLed, OUTPUT);
digitalWrite(pinoLed, LOW);
}

void loop() {
  if(digitalRead(PinoSensor)==HIGH){
      digitalWrite(pinoLed, HIGH);
  }else{
    digitalWrite(pinoLed, LOW);
  }
}
