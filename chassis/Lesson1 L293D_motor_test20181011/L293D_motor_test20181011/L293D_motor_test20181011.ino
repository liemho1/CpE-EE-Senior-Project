// VEEDOOO PROGRAMMING SMART CAR
//  LESSON 1  TEST THE 4 WHEELS
/* This program will make the car go forward for 1s, and then stop for 0.2s, then go backward for 1s, stop for 0.2s,
then turn left spin for 1s, stop for 0.2s, and finally turn right spin for 1s, stop for 0.2s.
this 4 ways movement will go over and over again until the power off.  */
#include <AFMotor.h>      //include the AFMotor library file
AF_DCMotor motorLF(1, MOTOR12_2KHZ);  //according to the wiring connection, define the M1 to Left Front motor as motorLF
AF_DCMotor motorLB(2, MOTOR12_2KHZ);  //according to the wiring connection, define the M2 to Left Back motor as motorLB
AF_DCMotor motorRB(3, MOTOR12_2KHZ);  //according to the wiring connection, define the M3 to Right Back motor as motorRB
AF_DCMotor motorRF(4, MOTOR12_2KHZ);  //according to the wiring connection, define the M4 to Right Front motor as motorRF

void setup() {  // setup function, will be only run one time when started
Serial.begin(9600);   // set the communicate rate to 9600
motorLF.setSpeed(120);  //Set the 4 motors speed to 150, it could be change between 0~255
motorLB.setSpeed(120);
motorRF.setSpeed(120);
motorRB.setSpeed(120);
}

void loop(){  // loop function, will run this part over and over again
forward();   // call the forward function, make the car move forward
delay(1000);  // delay means the forward will last for 1000ms, 1000ms = 1 second
stop();  // call the stop function, stop the car
delay(200); // stop for 200ms
backward();
delay(1000);
stop();
delay(200);
leftspin();
delay(1000);
stop();
delay(200);
rightspin();
delay(1000);
stop();
delay(200);
}

void forward()    // to make the car run forward, just let the 4 wheels all run forward
{
 motorLF.run(FORWARD);
 motorLB.run(FORWARD); 
 motorRF.run(FORWARD);
 motorRB.run(FORWARD);
  }

void backward()  // to make the car run backward, just let the 4 wheels all run backward
{
motorLF.run(BACKWARD);
motorLB.run(BACKWARD);
motorRF.run(BACKWARD);
motorRB.run(BACKWARD);  
  }

void left() // to make the car turn left, just let the 2 left wheels stop, and make the 2 right wheels move forward
{
motorLF.run(RELEASE);
motorLB.run(RELEASE);
motorRF.run(FORWARD);  
motorRB.run(FORWARD);
}

void leftspin() // to make the car leftspin, just let the 2 left wheels backward, and make the 2 right wheels move forward
{
motorLF.run(BACKWARD);
motorLB.run(BACKWARD);
motorRF.run(FORWARD);  
motorRB.run(FORWARD);
}

void right() // to make the car turn right, just let the 2 left wheels move forward, and make the 2 right wheels keep stop
{
 motorLF.run(FORWARD);
 motorLB.run(FORWARD); 
 motorRF.run(RELEASE);
 motorRB.run(RELEASE);
  }

void rightspin()  // to make the car rightspin, just let the 2 left wheels forward, and make the 2 right wheels move backward
{
 motorLF.run(FORWARD);
 motorLB.run(FORWARD); 
 motorRF.run(BACKWARD);
 motorRB.run(BACKWARD);
  }  

void stop() // to make the car stop, just let the 4 wheels keep stop by the RELEASE setting
{
motorLF.run(RELEASE);
motorLB.run(RELEASE);
motorRF.run(RELEASE);  
motorRB.run(RELEASE);
  }  
  
