const int pinoLED = 10; 
const int pinoPOT = A5; 
int leituraA5 = 0;

float luminosidadeLED = 0;

void setup(){
   /*Define a porta de saída*/
   pinMode(pinoLED, OUTPUT);
   /*Define a porta de entrada*/
   pinMode(pinoPOT, INPUT); 
}

void loop(){
  /*Valor recebido na porta lógica*/
  leituraA5 = analogRead(pinoPOT);
  luminosidadeLED = map(leituraA5, 0, 1023, 0, 255); 
  analogWrite(pinoLED, luminosidadeLED);
}
