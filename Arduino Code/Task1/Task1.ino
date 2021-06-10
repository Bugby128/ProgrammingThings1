#include <Zumo32U4.h>

Zumo32U4Motors motors;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600); 
}

void loop() {
  int input = Serial1.read(); 
  switch (input){
      case'U':
      motors.setSpeeds(150,150);
      break;
      
      case'L':
      motors.setSpeeds(-100, 100);
      break;
    
      case'R':
      motors.setSpeeds(100, -100);
      break;
      
      case 'D':
      motors.setSpeeds(-150,-150);
      break;

      case'S':
      motors.setSpeeds(0, 0);
      break;
    }

}



  
