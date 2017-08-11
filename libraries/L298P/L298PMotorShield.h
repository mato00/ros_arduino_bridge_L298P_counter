#ifndef _L298PMOTORSHIELD_H_
#define _L298PMOTORSHIELD_H_

#include <Arduino.h>

class L298PMotorShield{
public:
  // constructor
  L298PMotorShield();
  L298PMotorShield(unsigned char INA, unsigned char PWMA, unsigned char INB, unsigned char PWMB);
  //public methods
  void init();
  void setM1Speed(int speed);
  void setM2Speed(int speed);
  void setSpeeds(int m1speed, int m2speed);

private:
  static const unsigned char _INA = 4; //电机A正反控制端
  static const unsigned char _PWMA = 5; //电机A调速端
  static const unsigned char _INB = 7; //电机B正反控制端
  static const unsigned char _PWMB = 6; //电机B调速端
};

#endif
