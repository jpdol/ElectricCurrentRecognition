int cont = 0;
int inicial = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  inicial = millis();
  while(millis() - inicial < 1000){
    analogRead(A0);
    cont++;
  }
  Serial.println(cont);
  cont=0;
  inicial = 0;
}
