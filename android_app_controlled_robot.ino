#include <SoftwareSerial.h>
SoftwareSerial BT(7 , 8); // RX, TX

int M_R_1 = 9;    //right motor wire 1
int M_R_2 = 10;   //right motor wire 2
int M_L_1 = 11;   //left motor wire 1
int M_L_2 = 12;   //left motor wire 2

void setup()
{ //define 4 pins of motors as output
  pinMode(M_R_1, OUTPUT);
  pinMode(M_R_2, OUTPUT);
  pinMode(M_L_1, OUTPUT);
  pinMode(M_L_2, OUTPUT);
  Serial.begin(115200);
  BT.begin(9600);
  Serial.println("Keyboard Controlled Robot");
}

void loop()
{
  if (BT.available() > 0)
  {
    char data = BT.read();
    Serial.println(data);
    BT.println(data);
    if (data == 'w')
    {
      // forward
      Serial.println("Forward");
      BT.println("Forward");
      digitalWrite(M_L_1, 1);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 1);
      digitalWrite(M_R_2, 0);
    }
    else if (data == 'z')
    {
      // backward
      Serial.println("Backward");
      BT.println("Backward");
      digitalWrite(M_L_1, 0);
      digitalWrite(M_L_2, 1);
      digitalWrite(M_R_1, 0);
      digitalWrite(M_R_2, 1);
    }
    else if (data == 'a')
    {
      // left
      Serial.println("Left");
      BT.println("Left");
      digitalWrite(M_L_1, 0);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 1);
      digitalWrite(M_R_2, 0);
    }
    else if (data == 'd')
    {
      // right
      Serial.println("Right");
      BT.println("Right");
      digitalWrite(M_L_1, 1);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 0);
      digitalWrite(M_R_2, 0);
    }
    else if (data == 's' )
    {
      // stop
      Serial.println("Stop");
      BT.println("Stop");
      digitalWrite(M_L_1, 0);
      digitalWrite(M_L_2, 0);
      digitalWrite(M_R_1, 0);
      digitalWrite(M_R_2, 0);
    }
  }
}
