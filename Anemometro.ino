#define pinoLed 13
#define PinoSensor 23

int estadoOn = 0;
int estadoOff = 0;
int rpm;
unsigned long timeold;
volatile byte cont;
float velocidade; 

unsigned int pulsos_por_volta = 20;


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
cont = 0; 
rpm = 0;
timeold = 0;
}


void loop() {


if (millis() - timeold >= 1000)
  {
    if(digitalRead(PinoSensor)==HIGH){
    estadoOn = 1;
    estadoOff = 1;
  }
    //Desabilita interrupcao durante o calculo
    detachInterrupt(0);    
    rpm = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * cont;
    timeold = millis();
    cont = 0;
    //Mostra o valor de RPM no serial monitor
    Serial.print("RPM = ");
    Serial.println(rpm, DEC);

    velocidade = (rpm*0,0256*3.14159265359*3,6)/60;


    //Habilita interrupcao
    attachInterrupt(digitalPinToInterrupt(PinoSensor), SensorInterrupt, RISING); //RISING
  }
  
  //Serial.println(cont);

  
  }
