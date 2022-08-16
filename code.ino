int m1 = 7;
int m2 = 6;
int m3 = 4;
int m4 = 5;

bool L_IR;
bool R_IR;
bool B_IR;

int LIR = 10;
int RIR = 8;
int BIR = 9;


int trigPin = 3;
int echoPin = 2;
long duration;
int distance;


void setup() 
{
  pinMode(LIR,INPUT);
  pinMode(RIR,INPUT);
  pinMode(BIR,INPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = 0.034*(duration/2);
  
  L_IR = digitalRead(LIR);
  R_IR = digitalRead(RIR);
  B_IR = digitalRead(BIR);
  
  if(distance >= 10 && distance <= 30)
  {
    if(L_IR == 0 & R_IR == 1)
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,HIGH);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    } else if(L_IR == 1 & R_IR == 0)
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,HIGH);      
    } else if(L_IR == 1 & R_IR == 1)
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    } else
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,LOW);
    }

  } else if(B_IR == 1 && distance <= 5)
  {
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
  } else
  {
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
  }
}
