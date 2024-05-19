
#define pinoLed 13
#define PinoSensor 15

int estadoOn = 0;
int estadoOff = 0;
int cont = 0;   
int aux = 0;
unsigned long millisContador = millis();
volatile bool estado = false;
unsigned long timeold;


void setup() {

Serial.begin(115200);
pinMode(PinoSensor, INPUT);
pinMode(pinoLed, OUTPUT);
}

void loop() {
  
  if(digitalRead(PinoSensor)==HIGH){
    estadoOn = 1;
  }
  else{
    estadoOff = 1;
  }
  if(estadoOn == estadoOff){
    cont = cont + 1; 
    Serial.println(cont);
    estadoOn = 0;
    estadoOff = 0;
  }
}


/*
if (millis() - timeold >= 1000){
  if(digitalRead(PinoSensor)==HIGH){      
      digitalWrite(pinoLed, HIGH);
      detachInterrupt(digitalPinToInterrupt(PinoSensor));

  }else{
    digitalWrite(pinoLed, LOW);
    Serial.println(cont);
  }  
}
}*/
