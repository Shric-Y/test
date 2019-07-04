void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop()
{
  if(Serial.available()>0)
    {
      income=Serial.read();
        switch(income)
        {
          case 'f':
              forward();
              break;
            case 'b':
              backward();
              break;
            case 'l':
              left();
              break;
            case 'r':
              right();
              break;
            case 's':
              stop();
              break;
            default:
              break;
        }
    }
}

void forward()
{
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}

void backward()
{
  digitalWrite(2,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);

  digitalWrite(8,HIGH);//倒车灯亮
  digitalWrite(7,LOW);
}

void left()
{
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  
  digitalWrite(6,HIGH);//左转向灯亮
  digitalWrite(5,LOW);
}

void right()
{
  digitalWrite(2,HIGH);
  digitalWrite(1,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  
  digitalWrite(5,HIGH);//右转向灯亮
  digitalWrite(6,LOW);
}

void stop()
{
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
}
