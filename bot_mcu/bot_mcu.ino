#include<ESP8266WiFi.h>
#define EN1 D6
#define EN2 D7
int x=0;
long duration=0;
const int trigP=D1;
const int echoP=D2;
int LS=0;
int RS=0;
void Setup()
{
  Serial.begin(11500);
  pinMode(EN1,OUTPUT); 
  pinMode(EN2,OUTPUT);
  pinMode(trigP,OUTPUT);
  pinMode(echoP,INPUT);
}
void loop()
{
  digitalWrite(trigP,LOW);
  delayMicroseconds(2);
  digitalWrite(trigP,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigP,LOW);
  duration=pulseIn(echoP,HIGH);
  x=duration*0.034/2;
  if(x>70)
  {
    LS=1000;
    RS=1000;
  }
  else
  {
    LS=1.49404141e+02*x-1.16743968e-02*x*x-3.40756256e-04*x*x*x;
    RS=3.36418399e+02*x+2.05632547e+00*x*x-2.47270951e-03*x*x*x;
  }
  LS=LS-(LS%100);
  RS=RS-(RS%100);
  analogWrite(EN1,LS);
  analogWrite(EN2,RS);
  
}
