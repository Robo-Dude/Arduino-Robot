#include <Servo.h>.
#include<SoftwareSerial.h>
#define TxD 7
#define RxD 8
#define LED_PIN 13
SoftwareSerial bluetoothSerial(7, 8);

char c;
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;
Servo myServo7;
Servo myServo8;
void setup() {
  // put your setup code here, to run once:
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
  myServo1.attach(2);
  myServo2.attach(3);
  myServo3.attach(4);
  myServo4.attach(5);
  myServo5.attach(6);
  myServo6.attach(11);
  myServo7.attach(12);
  myServo8.attach(10);
  
  myServo1.write(90);
  myServo2.write(90);
  myServo3.write(90);
  myServo4.write(90);
  myServo5.write(90);
  myServo6.write(30);
  myServo7.write(140);
  myServo8.write(0);
  
}

void loop() 
  //put your main code here, to run repeatedly:
  {
    if(bluetoothSerial.available()>0)
 {
  c=bluetoothSerial.read();
  Serial.print(c);
  if (c=='1')
  {int j;
  for(int i=0;i<=180;i++){  
  myServo1.write(i);
  myServo3.write(i);
  delay (25);
  j=180-i;
  myServo2.write(j);
  myServo4.write(j);
  delay(5);
  }
  for(int i=180;i>=0;i--){  
  myServo1.write(i);
  myServo3.write(i);
  delay (25);
  j=180-i;
  myServo2.write(j); 
  myServo4.write(j);
  delay(5);
 }}
   if (c=='2')
   {
     myServo1.write(160);
     myServo2.write(20);
     myServo3.write(160);
     myServo4.write(20);
     myServo5.write(90);
     myServo6.write(30);
     myServo7.write(140);
     myServo8.write(170);
   }
     if (c=='3')
     {
      {
          myServo5.write(140);
          myServo8.write(130);
          delay (4000);  
        } 
        { myServo6.write(80);
          myServo7.write(90);
          delay (4000);  
        }
        {
           myServo5.write(90);
           myServo6.write(30);
           myServo7.write(140);
           myServo8.write(170);
           delay (4000);

        }
     }
 
 
 
 
 
 
 
 
 
 }
  
  }
