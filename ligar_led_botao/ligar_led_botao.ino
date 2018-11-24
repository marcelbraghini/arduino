/* Pino utilizado pelo push button*/
const int pushButton = 7;
/* Pino utilizado pelo led*/
const int led = 2;
/* Armazena o valor lido*/
int leitura = 0; 
/* Controla do estado do led*/
int estado = 0; 

void setup() {
/* Define a porta como entrada*/
pinMode(pushButton, INPUT);
/* Define a porta como saída*/
pinMode(led, OUTPUT); 
}

void loop(){
  /*Faz a leitura do valor de entrada*/
  leitura = digitalRead(pushButton);

  if((leitura == 0) && (estado == 0)){ 
  /*Liga o led*/  
  digitalWrite(led, HIGH);
  /*Altera o estado do led para ligado*/
  estado = 1; 
  delay(200);
  }else{
    if((leitura == 0) && (estado == 1)){
      /*Desliga o led*/  
      digitalWrite(led, LOW);
      /*Altera o estado do led para desligado*/
      estado = 0; 
      delay(200);
    }
  }
}