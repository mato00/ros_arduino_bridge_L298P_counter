#include "L298PMotorShield.h"

L298PMotorShield::L298PMotorShield()
{
}

L298PMotorShield::L298PMotorShield(unsigned char INA, unsigned char PWMA, unsigned char INB, unsigned char PWMB)
{
}

void L298PMotorShield::init()
{
  pinMode(_INA, OUTPUT);
  pinMode(_INB, OUTPUT);
  pinMode(_PWMA, OUTPUT);
  pinMode(_PWMB, OUTPUT);
}

// set speed for left motor,speed between -400 to 400
void L298PMotorShield::setM1Speed(int speed)
{
  unsigned char reverse = 0;

  if(speed < 0)
  {
    speed = -speed; //make speed a positive quantity
    reverse = 1;  //reverse the direction
  }
  if(speed > 400)
    speed = 400;

  analogWrite(_PWMA,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255

  if (reverse)
    digitalWrite(_INA,LOW);
  else
    digitalWrite(_INA,HIGH);
}

//set speed for motor right
void L298PMotorShield::setM2Speed(int speed)
{
  unsigned char reverse = 0;
  
  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;

  analogWrite(_PWMB,speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
 
  if (reverse)
    digitalWrite(_INB,LOW);
  else
    digitalWrite(_INB,HIGH);
}

//set speed for motor left and right
void L298PMotorShield::setSpeeds(int m1speed, int m2speed)
{
  setM1Speed(m1speed);
  setM2Speed(m2speed);
}

