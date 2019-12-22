// VEEDOOO PROGRAMMING SMART CAR
//  LESSON 4  OBSTACLE AVOIDANCE MODE
/* This program will make the car go with a black line with 2 detective sensor input */
#include <AFMotor.h>      //include the AFMotor library file
#include <Servo.h>       //include the Servo library file
AF_DCMotor motorLF(1, MOTOR12_2KHZ);  //according to the wiring connection, define the M1 to Left Front motor as motorLF
AF_DCMotor motorLB(2, MOTOR12_2KHZ);  //according to the wiring connection, define the M2 to Left Back motor as motorLB
AF_DCMotor motorRB(3, MOTOR12_2KHZ);  //according to the wiring connection, define the M3 to Right Back motor as motorRB
AF_DCMotor motorRF(4, MOTOR12_2KHZ);  //according to the wiring connection, define the M4 to Right Front motor as motorRF
int speed=100;  
Servo s; //超声波转向舵机
int trig=16; //发射信号
int echo=17; //接收信号
unsigned int S; //距离存储

void setup() {
Serial.begin(9600); //设置波特率
pinMode(trig,OUTPUT); //设置引脚模式
pinMode(echo,INPUT);
motorLF.setSpeed(speed); //set the motors speed, it could be change between 0~255
motorLB.setSpeed(speed);
motorRF.setSpeed(speed);
motorRB.setSpeed(speed);
s.attach(10); //定义舵机所用引脚
s.write(90); //初始化舵机角度
delay(1000); //开机延时
}


void loop() { //主函数
/*s.write(90); 
delay(600);
s.write(170); 
delay(600);
s.write(10); 
delay(600);*/

s.write(90); //舵机中位
range(); //执行测距函数
if(S<=15){ //判断障碍物距离，距离太近
backward(); //后退
delay(500); //后退时间
}
if(S<=40&&S>15){ //距离中等
turn(); //运行转向判断函数
}
if(S>40){ //距离充足
forward(); //运行直行函数
}
}


void turn(){ //判断转向函数
stop(); //停止所用电机
s.write(170); //舵机转到170度既左边（角度与安装方式有关）
delay(500); //留时间给舵机转向
range(); //运行测距函数
s.write(90); //测距完成，舵机回到中位
delay(500); //留时间给舵机转向
if (S>25) {leftspin();} //判断左边障碍物距离，如果距离充足,运行左转 
else {
s.write(10); //否则，舵机转动到10度，测右边距离
delay(600);
range(); //测距
s.write(90); //中位
delay(600);
if(S>25){ rightspin();
} //右转
else{ backward(); //判断右边距离，距离充足右转否则后退
int x=random(1); //产生一个0到1的随机数 
if (x=0){rightspin();} 
else{leftspin();} //判断随机数
} //否则后退，并随机转向
}
}


void range(){ //测距函数
digitalWrite(trig,LOW); //测距
delayMicroseconds(2); //延时2微秒
digitalWrite(trig,HIGH);
delayMicroseconds(20);
digitalWrite(trig,LOW);
int distance = pulseIn(echo,HIGH); //读取高电平时间
distance = distance/58; //按照公式计算
S = distance; //把值赋给S
Serial.println(S); //向串口发送S的值，可以在显示器上显示距离
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
delay(1000);   //the delay time must adjust with the speed, to leave enough time for the car to complete a 90 degree turn around. If the speed was high, then the delay time could be lower.
stop(); 
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
delay(1000);  //the delay time must adjust with the speed, to leave enough time for the car to complete a 90 degree turn around.
stop(); 
  }  

void stop() // to make the car stop, just let the 4 wheels keep stop by the RELEASE setting
{
motorLF.run(RELEASE);
motorLB.run(RELEASE);
motorRF.run(RELEASE);  
motorRB.run(RELEASE);
  }  
  
