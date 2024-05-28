#define pinoLed 13
#define PinoSensor 23

int estadoOn = 0;
int estadoOff = 0;
int cont = 0;   
int aux = 0;
unsigned long millisContador = millis();
volatile bool estado = false;


void IRAM_ATTR SensorInterrupt() {
if(estadoOn == 1 && estadoOff == 1){
    cont = cont + 1; 
    estadoOn = 0;
    estadoOff = 0;    
  }
}

void setup() {

Serial.begin(115200);
pinMode(PinoSensor, INPUT);
pinMode(pinoLed, OUTPUT);
attachInterrupt(digitalPinToInterrupt(PinoSensor), SensorInterrupt, RISING); //RISING

}


void loop() {

  if(digitalRead(PinoSensor)==HIGH){
    estadoOn = 1;
    estadoOff = 1;
  }
  Serial.println(cont);
  
}
