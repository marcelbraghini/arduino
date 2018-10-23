//Exemplo de luz que acende e apaga
void setup() {
  //Diz que o pino 13 vai ser de saída
  pinMode(13, OUTPUT);
}

void loop() {
  //Energiza o pino 13 para acender o led
  digitalWrite(13, HIGH);
  //Cria um delay em milisegundos
  delay(2000);

  //Tira a energia do pino 13 para apagar o led
  digitalWrite(13, LOW);
  //Cria um delay em milisegundos
  delay(2000);
}
