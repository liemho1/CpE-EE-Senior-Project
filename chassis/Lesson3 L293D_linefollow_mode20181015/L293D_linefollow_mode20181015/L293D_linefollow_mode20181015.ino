// VEEDOOO PROGRAMMING SMART CAR
//  LESSON 3  LINE FOLLOWING MODE
/* This program will make the car go with a black line with 2 detective sensor input */
#include <AFMotor.h>      //include the AFMotor library file
AF_DCMotor motorLF(1, MOTOR12_2KHZ);  //according to the wiring connection, define the M1 to Left Front motor as motorLF
AF_DCMotor motorLB(2, MOTOR12_2KHZ);  //according to the wiring connection, define the M2 to Left Back motor as motorLB
AF_DCMotor motorRB(3, MOTOR12_2KHZ);  //according to the wiring connection, define the M3 to Right Back motor as motorRB
AF_DCMotor motorRF(4, MOTOR12_2KHZ);  //according to the wiring connection, define the M4 to Right Front motor as motorRF
int speed=150;  
const int SensorLeft = 14;       //左循迹红外传感器(A0)
const int SensorRight = 15;     //右循迹红外传感器(A1)
int SL;    //左循迹红外传感器状态
int SR;    //右循迹红外传感器状态

void setup() {  // setup function, will be run only one time when started
Serial.begin(9600); //set the communicate rate to 9600
motorLF.setSpeed(speed); //set the motors speed, it could be change between 0~255
motorLB.setSpeed(speed);
motorRF.setSpeed(speed);
motorRB.setSpeed(speed);
}

void loop(){  // loop function, will run this part over and over again
//   检测到黑线输出高， 同时开关指示灯灭；  检测到白色区域输出低， 同时开关指示灯亮；
  SR = digitalRead(SensorRight);//
  SL = digitalRead(SensorLeft);//
  if (SL==LOW&&SR==LOW)
    forward();   //调用前进函数
 if (SL==HIGH&&SR==LOW)// 左循迹红外传感器,检测到信号，车子向右偏离轨道，向左转 
       leftspin();
 //   while(SL);
   else if 
  (SR==HIGH&&SL==LOW) // 右循迹红外传感器,检测到信号，车子向左偏离轨道，向右转  
       rightspin();
 //   while(SR);
    
 else  // 两边都检测到黑线, 停止
  stop();
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
  
