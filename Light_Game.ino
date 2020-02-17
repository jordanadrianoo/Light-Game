//Jordan

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

//Target LED
int target=0;
int choosenLED=0;


//Buttons
int buttonPin=30;
int button=0;

//wait time for each pattern 
int setupStageWait=450;
int mainStageWait =200;
int wait1 =150;
int wait2 =80;
int wait3 =20;
int wait4 =20;
int wait5 =150;
int wait6 =150;
int wait7 =200;
int wait8 =400;



void setup() 
{
  Serial.begin(9600);
  
  for(int i=2;i<=13;i++) // sets all pins from 2 through 13 as OUTPUT
  {
  pinMode(i,OUTPUT);
  }

  pinMode(buttonPin,INPUT);
}


  void setupStage()// Sets up a random target LED for the user to try to land on
  {
    target=((random(12))+2);
    Serial.print("The target is ");
    Serial.println(target);
    for(int i=0; i<3;i++)
    {
    digitalWrite(target,HIGH);
    delay(setupStageWait);
    digitalWrite(target,LOW);
    delay(setupStageWait);
    }
  }

 void mainStage()//The main light stage, one light lights up at a time
 {
  choosenLED=0;
  while(true)
  {
  for(int i=2;i<14;i++)
  {
    button=digitalRead(buttonPin);
    
    digitalWrite(i,HIGH);
    choosenLED=i;
    if(button==1)
    {
      break;
    }
    delay(mainStageWait);
    digitalWrite(i,LOW);
  }
  if(button==1)
  {
    break;
  }
  }
  
  Serial.print("you have coosen a color in spot ");
  Serial.println(choosenLED-1);
  check();
  
  
 }

  void check()// Checks to see if the user landed on the target
  {
    if(choosenLED==target)
    {
      correctPattern();
    }
    else
    {
      wrongPattern();
    }
  }

  void correctPattern()// DIsplays an LED pattern when the user is correct
{
  Serial.println("\n");
  for(int i=target;i<target+12;i++)
  {
    if(i<=13)
    {
    Serial.println((i));
    digitalWrite((i),HIGH); 
    }
    else
    {
    Serial.println((i%14)+2);
    digitalWrite((i%14)+2,HIGH); 
    }
    delay(20);
  }
  mainStageWait= mainStageWait-25;
}

void wrongPattern()
{
  digitalWrite(target,HIGH);

  for(int i=0;i<3;i++)
  {
    digitalWrite(choosenLED,HIGH);
    delay(400);
    digitalWrite(choosenLED,LOW);
    delay(400);
  }

  mainStageWait=200;
  
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
      delay(wait7);
      digitalWrite(i,LOW);
    }
  }
  digitalWrite(13,LOW);
 }

 void pattern8(int n) // The binary pattern
 {
  int lightorder[n]; // sets array size

  for(int i=0;i<n;i++) // sets array at value zero
  {
    lightorder[i]=0;
    Serial.print(lightorder[i]);
    delay(100);
  }
  Serial.print(": Start state \n");
  delay(2000);

  for(int x=pow(2,n)-1;x>=0;x--)
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
        
        break;
      }
    }
    break;
  }

   for(int i=0;i<n;i++) 
  {
    Serial.print(lightorder[i]);
   
  }
  Serial.print(": Finsihed state \n");
  

  
 for(int i=0;i<n;i++)
 {
  if(lightorder[(n-1)-i]==1)
  {
    digitalWrite((i+2),HIGH);
  }
  else
  {
    digitalWrite((i+2),LOW);
  }
  
 }
 delay(wait8);   
    
  }
  }
 

 
void loop() 
{

  pattern1();
  while(true)
  {
  setupStage();
  mainStage();
  transition();
  }
     
}
