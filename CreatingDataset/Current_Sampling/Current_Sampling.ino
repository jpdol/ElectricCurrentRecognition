#define TAM 300
#define ZeroCurrent 0.5
float entrada[TAM];
int i = 0;

float volts_por_unidade = 0.004887586; // 5/1023
float sensibilidade = 0.138; // 5A
//float sensibilidade = 0.062; // 30A

float x;
float aux;

float getCurrent(int pin){
  return (((analogRead(pin)-512)*volts_por_unidade)/sensibilidade);
}

void setup() {
  Serial.begin(9600); 
}

void loop() {
  while(1){
    x = getCurrent(A0);
    aux = getCurrent(A0);
    if (x<ZeroCurrent && x>-ZeroCurrent && aux>ZeroCurrent){
      entrada[0] = x;
      entrada[1] = aux;
      i = 2;
      break;
    }
  }
  while (i<TAM){
    x = getCurrent(A0);
    entrada[i]=x;
    i++;
  }

  if(i==TAM){
    for (int j; j<TAM; j++){
      if ((entrada[j]<ZeroCurrent) && (entrada[j]>-ZeroCurrent)){
        entrada[j]=0;
      }
      Serial.println(entrada[j]); 
    }
    i=0;
  }
}
