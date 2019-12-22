/* In this program, you will learn how to use bluetooth control your car via smart phone.
 Install the VEEDOOO bluetooth control APP in your smart phone, and scan and connect to the BT05 module
after connect successfully, you could use your android smart phone to control the car to go forward, backward, turn left and right. */

#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,19);    // the ble bluetooth module TXD connect to pin 2, RXD connect to pin 19
AF_DCMotor motorLF(1, MOTOR12_2KHZ);//  the Left Front motor connect to M1
AF_DCMotor motorLB(2, MOTOR12_2KHZ);// the Left Back motor connect to M2
AF_DCMotor motorRB(3, MOTOR12_2KHZ);// the Right Back motor connect to M3
AF_DCMotor motorRF(4, MOTOR12_2KHZ);// the Right Front motor connect to M4
int carSpeed; 

void setup()
{
carSpeed=250;
motorLF.setSpeed(carSpeed);
motorLB.setSpeed(carSpeed);
motorRB.setSpeed(carSpeed);
motorRF.setSpeed(carSpeed);
motorLF.run(RELEASE);
motorLB.run(RELEASE);
motorRB.run(RELEASE);
motorRF.run(RELEASE);
    Serial.begin(115200);
 //   pinMode(LED_BUILTIN, OUTPUT);
    while (!Serial) {
  }
//  Serial.println("Hi!");
  mySerial.begin(9600);
//  mySerial.println("Hello, world?");
}

void loop(){
  int i=5;
  if(mySerial.available()>0)
 {
      i=mySerial.read(); //接收蓝牙传来的数据
      switch(i)
      {
        case 1://前进
          forward();
          /* digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
           delay(1000);                       // wait for a second
           digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
           delay(1000); */
           break;
       case 2://后退
         backward();
       /*   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
           delay(1000);                       // wait for a second
           digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
           delay(1000);*/ 
           break; 
       case 3://left
         leftspin();
        /*  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
           delay(1000);                       // wait for a second
           digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
           delay(1000); */
           break;
      case 4://right
         rightspin();
          /*digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
           delay(1000);                       // wait for a second
           digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
           delay(1000); */
           break;
      case 5://stop
         stop();
         /* digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
           delay(1000);                       // wait for a second
           digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
           delay(1000); */
          break;
        }
    }
}

void forward()
{
 motorLF.run(FORWARD);
 motorLB.run(FORWARD); 
 motorRB.run(FORWARD);
 motorRF.run(FORWARD);
  }

void backward()
{
motorLF.run(BACKWARD);
motorLB.run(BACKWARD);
motorRB.run(BACKWARD);
motorRF.run(BACKWARD);  
  }

void left()
{
motorLF.run(RELEASE);
motorLB.run(RELEASE);
motorRB.run(FORWARD);
motorRF.run(FORWARD);  
}

void leftspin()
{
motorLF.run(BACKWARD);
motorLB.run(BACKWARD);
motorRB.run(FORWARD);
motorRF.run(FORWARD);  
}

void right()
{
 motorLF.run(FORWARD);
 motorLB.run(FORWARD); 
 motorRB.run(RELEASE);
 motorRF.run(RELEASE);
  }

void rightspin()
{
 motorLF.run(FORWARD);
 motorLB.run(FORWARD); 
 motorRB.run(BACKWARD);
 motorRF.run(BACKWARD);
  }  

void stop()
{
motorLF.run(RELEASE);
motorLB.run(RELEASE);
motorRB.run(RELEASE);
motorRF.run(RELEASE);  
  } 

