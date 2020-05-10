#include<SoftwareSerial.h>

SoftwareSerial mySerial (2, 3);

#define led1 9
#define led2 10
#define led3 11

String val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available() == 1)
  {
    val = mySerial.readString();
    val.trim();
    Serial.println(val);
    if(val.length() > 3)
    {
      val.remove(0, val.length()-3);
      if(val.indexOf(',') == 0)
      {
        val.remove(0, 1);
      }
    }
    else
    {
      if(val.indexOf(',') == 0)
      {
        val.remove(0, 1);
      }
    }
    int num = val.toInt();
    if(num <= 100)
    {
      int pwm_val = map(num, 0, 100, 0, 255);
      analogWrite(led1, pwm_val);
    }
    if(num >= 200 && num <= 300)
    {
      int pwm_val = map(num, 200, 300, 0, 255);
      analogWrite(led2, pwm_val);
    }
    if(num >= 400 && num <= 500)
    {
      int pwm_val = map(num, 400, 500, 0, 255);
      analogWrite(led3, pwm_val);
    }   
  }
}
