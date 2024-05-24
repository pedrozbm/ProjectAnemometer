
#define pinoLed 13
#define PinoSensor 23


volatile int cont = 0;
volatile bool lastState;
volatile uint32_t debounceTimeout = 0;

uint32_t saveDebounceTimeout;
bool saveLastState;
int save;
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR SensorInterrupt() {

portENTER_CRITICAL_ISR(&mux); 
    cont++;
    lastState = digitalRead(PinoSensor);  
    debounceTimeout = xTaskGetTickCount(); //versão do millis () que funciona a partir da interrupção //version of millis() that works from interrupt
    portEXIT_CRITICAL_ISR(&mux);
}

void setup() {
  Serial.begin(115200);
  pinMode(PinoSensor, INPUT);
  pinMode(pinoLed, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PinoSensor), SensorInterrupt, FALLING); //RISING
  
}

void loop() {
  /*
  if (millis() - timeold >= 1000) {
    if (estado) { // Se o estado for verdadeiro, acende o LED
      digitalWrite(pinoLed, HIGH);
      
       //Serial.println("Kendy: "+cont);
    } else { // Se o estado for falso, apaga o LED
      digitalWrite(pinoLed, LOW);
    }
    timeold = millis(); // Atualiza o tempo
   // Serial.println(cont);
   }*/
   portENTER_CRITICAL_ISR(&mux); // início da seção crítica
      save  = cont;
      saveDebounceTimeout = debounceTimeout;
      saveLastState  = lastState;
  portEXIT_CRITICAL_ISR(&mux); 
 bool currentState = digitalRead(PinoSensor);
  if(currentState != saveLastState)
    {
      saveDebounceTimeout = millis();
    }
  Serial.println(cont);
}
