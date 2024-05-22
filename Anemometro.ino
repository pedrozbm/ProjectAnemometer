#define pinoLed 13
#define PinoSensor 23

int cont = 0;
volatile bool estado = false;
unsigned long timeold;

void IRAM_ATTR handleInterrupt() {
  if(estado = !estado){ // Alterna o estado sempre que uma interrupção ocorre
  cont++;
  }
  //Serial.println(cont);
}

void setup() {
  Serial.begin(115200);
  pinMode(PinoSensor, INPUT);
  pinMode(pinoLed, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PinoSensor), handleInterrupt, FALLING); //RISING
}

void loop() {
  if (millis() - timeold >= 1000) {
    if (estado) { // Se o estado for verdadeiro, acende o LED
      digitalWrite(pinoLed, HIGH);
      
       //Serial.println("Kendy: "+cont);
    } else { // Se o estado for falso, apaga o LED
      digitalWrite(pinoLed, LOW);
    }
    timeold = millis(); // Atualiza o tempo
   // Serial.println(cont);
   }
  Serial.println(cont);

}
