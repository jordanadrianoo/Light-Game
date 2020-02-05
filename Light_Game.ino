// Top 4 LEDS
int tRed =13;
int tYellow =12;
int tBlue =11;
int tGreen =10;

//Middle 4 LEDS
int mRed =9;
int mYellow =8;
int mBlue =7;
int mGreen =6;

//Bottom 4 LEDS
int bRed =5;
int bYellow =4;
int bBlue =3;
int bGreen =2;

//wait time for each pattern 
int wait =150;
int wait2 =80;
int wait3 =20;
int wait4 =200;
int wait5 =100;

void setup() 
{
  Serial.begin(9600);
  
  for(int i=2;i<=13;i++) // sets all pins from 2 through 13 as OUTPUT
  {
  pinMode(i,OUTPUT);
  }
}

void pattern1() // LEDs light upwards in seperations of 4
{
  for(int x=0;x<4;x++)
  {
  for(int i=2;i<6;i++)
  {
    digitalWrite(i,HIGH);
    digitalWrite(i+4,HIGH);
    digitalWrite(i+8,HIGH);
    delay(wait);
    digitalWrite(i,LOW);
    digitalWrite(i+4,LOW);
    digitalWrite(i+8,LOW);
  }
  }
 }

 void pattern2() // LEDs roam up then back down
 {
   for(int i=2;i<18;i++)
  {
    digitalWrite(i,HIGH);
    digitalWrite(i-1,HIGH);
    digitalWrite(i-2,HIGH);
    digitalWrite(i-3,HIGH);
    delay(wait2);
    digitalWrite(i,LOW);
    digitalWrite(i-1,LOW);
    digitalWrite(i-2,LOW);
    digitalWrite(i-3,LOW); 
  }

  for(int i=17;i>0;i--)
  {
    digitalWrite(i,HIGH);
    digitalWrite(i-1,HIGH);
    digitalWrite(i-2,HIGH);
    digitalWrite(i-3,HIGH);
    delay(wait2);
    digitalWrite(i,LOW);
    digitalWrite(i-1,LOW);
    digitalWrite(i-2,LOW);
    digitalWrite(i-3,LOW); 
    
  }
  delay(wait2);
 }

 void pattern3()// End LEDs flash twords the middle
 {
  for(int i=2;i<8;i++)
  {
    digitalWrite(i,HIGH);
    digitalWrite(13-(i-2),HIGH);
    delay(wait3);
  }
  for(int i=2;i<8;i++)
  {
    digitalWrite(i,LOW);
    digitalWrite(13-(i-2),LOW);
    delay(wait3);
  }
 }

 void pattern4()
 {
  for(int x=2;x<14;x++)
  {
    digitalWrite(x,HIGH);
    digitalWrite(x-1,LOW);
   
    for(int i=2;i<x;i++)
    {
                digitalWrite(i,HIGH);
      delay(200);
      digitalWrite(i,LOW);
    }
  }
  digitalWrite(13,LOW);
 }

 void pattern5()
 {
  for(int i=2;i<14;i++)
  {
    digitalWrite(i,HIGH);
    delay(wait5);
    digitalWrite(i,LOW);
  }
  
 }
 
void loop() 
{
 pattern1();
 pattern3();
 pattern3();
 pattern2();
 pattern2();
 pattern3();
 pattern3();
 pattern5();
 pattern5();
 pattern5();
 pattern5();
 pattern3();
 pattern3();
}
