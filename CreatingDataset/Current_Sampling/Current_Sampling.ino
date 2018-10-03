#define TAM 300

float entrada[TAM];
int i = 0;

float volts_por_unidade = 0.004887586; // 5/1023
//float sensibilidade = 0.138; // 5A
float sensibilidade = 0.062; // 30A
float x;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  while (i<TAM){
    x = (((analogRead(A0) - 512)*volts_por_unidade)/sensibilidade);
    entrada[i]=x;
    i++;
  }

  if(i==TAM){
    for (int j; j<TAM; j++){
      Serial.println(entrada[j]); 
    }
    i=0;
  }

}
