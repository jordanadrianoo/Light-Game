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
int mainStageWait =100;
int wait1 =150;
int wait2 =80;
int wait3 =20;
int wait4 =20;
int wait5 =150;
int wait6 =150;
int wait7 =NULL;



void setup() 
{
  Serial.begin(9600);
  
  for(int i=2;i<=13;i++) // sets all pins from 2 through 13 as OUTPUT
  {
  pinMode(i,OUTPUT);
  }
}


 void mainStage()//The main light stage, one light lights up at a time
 {
  for(int i=2;i<14;i++)
  {
    digitalWrite(i,HIGH);
    delay(mainStageWait);
    digitalWrite(i,LOW);
  }
 }

  void transition()//Transition stage between patterns
 {
  pattern3();
  pattern4();
  pattern3();
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
    delay(wait1);
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

void pattern3()// End LEDs flash twords the middle (single version)
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

 void pattern4()// Middle LEDs flash twords ends (single version)
 {
      for(int i=7;i>1;i--)
  {
    digitalWrite(i,HIGH);
    digitalWrite(13-(i-2),HIGH);
    delay(wait4);
  }
        for(int i=7;i>1;i--)
  {
    digitalWrite(i,LOW);
    digitalWrite(13-(i-2),LOW);
    delay(wait4);
  }
 }
 
 void pattern5()// End LEDs flash twords the middle then back to end (filled version)
 {
   for(int i=2;i<8;i++)
  {
    digitalWrite(i,HIGH);
    digitalWrite(13-(i-2),HIGH);
    delay(wait5);
  }
      for(int i=7;i>1;i--)
  {
    digitalWrite(i,LOW);
    digitalWrite(13-(i-2),LOW);
    delay(wait5);
  }
 }
 
 void pattern6()// Middle LED's flash twords the end then back to middle (filled version)
 {
  for(int i=7;i>1;i--)
  {
    digitalWrite(i,HIGH);
    digitalWrite(13-(i-2),HIGH);
    delay(wait6);
  }
  for(int i=2;i<8;i++)
  {
    digitalWrite(i,LOW);
    digitalWrite(13-(i-2),LOW);
    delay(wait6);
  }
 }

 
 
 void pattern7() //pushes light upwards one at a time
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

 void pattern8(int n)
 {
  int lightorder[n]; // sets array size

  for(int i=0;i<n;i++) // sets array at value zero
  {
    lightorder[i]=0;
    Serial.println(n);
    delay(100);
  }

  for(int x=n-1;x>=0;x--)
  {
  while(true)
  {
    for(int i=n-1;i>=0;i--)
    {
      if(lightorder[i]==1)
      {
        lightorder[i]=0;
      }
      else
      {
        lightorder[i]=1;
        Serial.print("else");
        break;
      }
    }
    break;
  }
  for(int i=0;i<n;i++)
  {
    if(lightorder[i]==1)
    {
      digitalWrite(i+2,HIGH);
    }
    else
    {
      digitalWrite(i+2,LOW);
    }
    Serial.println(lightorder[i]);
    delay(300);
  }
  }
 }

 
void loop() 
{
  
   pattern8(9);

  
}
