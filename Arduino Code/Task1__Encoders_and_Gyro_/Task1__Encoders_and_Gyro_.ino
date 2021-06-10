#include "TurnSensor.h"
#include <Zumo32U4.h>

Zumo32U4Encoders encoders; 
Zumo32U4IMU imu;
Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600); 
  turnSensorSetup();
}

void loop() {
  int leftEncoders;
  int rightEncoders;
  int input = Serial1.read(); 
  leftEncoders = encoders.getCountsAndResetLeft();
  rightEncoders = encoders.getCountsAndResetRight();  
  turnSensorReset();
  switch (input){
      case'U':
      motors.setSpeeds(200,200);
      do {
      leftEncoders = encoders.getCountsLeft();
      rightEncoders = encoders.getCountsRight();
      }  while(leftEncoders<R&&rightEncoders<1500);
      motors.setSpeeds(0,0);
      break;
      
      case'L':
      motors.setSpeeds(-100, 100);
      while((int32_t)turnAngle < turnAngle90)
      {
        turnSensorUpdate();
      }
      motors.setSpeeds(0,0);
      break;
    
      case'R':
      motors.setSpeeds(100, -100);
      while((int32_t)turnAngle > -turnAngle90)
      {
        turnSensorUpdate();
      }
      motors.setSpeeds(0,0);
      break;
      
      case 'D':
      motors.setSpeeds(-200,-200);
      do {
      leftEncoders = encoders.getCountsLeft();
      rightEncoders = encoders.getCountsRight();
      }  while(leftEncoders>-1500&&rightEncoders>-1500);
      motors.setSpeeds(0,0);
      break;

      case'S':
      motors.setSpeeds(0, 0);
      break;
    }

}



  
