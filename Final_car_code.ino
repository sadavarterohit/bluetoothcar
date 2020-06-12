/* hello world */ 
int lf=8;
int lb=9;
int rf=10;
int rb=11;
int stopped=1;

char input;
void setup()
{
 pinMode(lf,OUTPUT);
 pinMode(rf,OUTPUT);
 pinMode(lb,OUTPUT);
 pinMode(rb,OUTPUT);

 Serial.begin(9600);
}
void stop()
{
  
  digitalWrite(lb,LOW);
  digitalWrite(lf,LOW);
  digitalWrite(rb,LOW);
  digitalWrite(rf,LOW);
}
void front()
{
  
  digitalWrite(lf,HIGH);
  digitalWrite(lb,LOW);
  digitalWrite(rb,LOW);
  digitalWrite(rf,HIGH);
}
void back()
{
  digitalWrite(lf,LOW);
  digitalWrite(rf,LOW);
  digitalWrite(lb,HIGH);
  digitalWrite(rb,HIGH);
}

void right()
{
  digitalWrite(rb,LOW);
  digitalWrite(lf,LOW);
  digitalWrite(rf,HIGH);
  digitalWrite(lb,HIGH);
}
void left()
{
  digitalWrite(lb,LOW);
  digitalWrite(lf,HIGH);
  digitalWrite(rb,HIGH);
  digitalWrite(rf,LOW);
}
void loop()
{
  
  if(Serial.available())
  {
      input='z';
      input=Serial.read();
      Serial.print(input);
      Serial.print("\t");
      
      if(input=='w')
      {
          if (stopped ==1)
          {       
            front();  
            stopped=0;
          }
          else
          {
            stopped=1;
            stop();
          }  
      }
      if(input=='a')
      {
       if(stopped==1) 
      
      { left();
      stopped=0;
      }
      else
          {
            stopped=1;
            stop();
          }  
      }
      if(input=='s')
      {
       if(stopped==1)
      { 
        back();
        stopped=0;
      else
          {
            stopped=1;
            stop();
          }  
      }
      if(input=='d')
      {
       if(stopped==1)
      { right();
          stopped=0;
      
      }
      else
          {
            stopped=1;
            stop();
          }  
      }
  }
  

}
 
 
