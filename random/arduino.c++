int sequencia[32] = {};
int botoes[4] = {8,9,10,11};
int leds[4] = {2,3,4,5};
int rodada = 0;
int passo = 0;
int botao_pressionado = 0;
bool gameover = false;
void setup() {
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);

  Serial.begin(9600);
}
void proximaRodada()
{
  int sorteio = random(4);
  sequencia[rodada] = sorteio;
  rodada++;
  Serial.print(sorteio);
}
void loop() {


  proximaRodada();
  reproduzirSequencia();
  aguardarJogador();
  if(gameover)
  {
    passo = 0;
    rodada = 0;
    sequencia[32] = {};
    gameover = false;
  }
  delay(1000);
}
void reproduzirSequencia()
{ 
  for(int i = 0; i<rodada; i++)
  {
    digitalWrite(leds[sequencia[i]],HIGH);
    delay(500);
    digitalWrite(leds[sequencia[i]],LOW);
    delay(100);
  }

}
void aguardarJogador()
{
  for(int i = 0; i<rodada;i++)
  { 
    bool jogou = false;
    while(!jogou){
      for(int i = 0; i <=3; i++)
      {
        if(digitalRead(botoes[i]) == LOW)
        {
          botao_pressionado = i;
          digitalWrite(leds[i], HIGH);
          delay(300);
          digitalWrite(leds[i],LOW);
          jogou = true;
        }
      }
    }
    if(sequencia[passo] != botao_pressionado)
    {
      for(int i = 0;i<=3;i++)
      {
        digitalWrite(leds[i],HIGH);
        delay(100);
        digitalWrite(leds[i],LOW);

      }
      gameover = true;
      break;
    }
    
    passo+=1;
  }
 
  
  passo = 0; 
}