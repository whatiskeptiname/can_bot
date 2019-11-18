#define mA1 12   // A motor
#define mA2 11
#define mB1 10   // B motor
#define mB2 9
#define  trigPin 8
#define  echoPin 7
#define buzzer 4
#include <Servo.h>
Servo servohand;
Servo servohead;

long int dist, duration;
char input;
void sensor_check()
{
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.

  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance

  dist = (duration / 2) / 29.1;

  //read tx inputa
  if (Serial.available() > 0)
  {
    input = Serial.read();
  }
 // else
 // {
 //   wait();
// }

  Serial.print(dist);
  Serial.print(" cm ");
  Serial.print("data: ");
  Serial.print(input);
  Serial.println();
}

//void beep()
//{
//  tone(buzzer, 900);
//  delay(200);
//  tone(buzzer, 1000);
//  delay(200);
//}

//void dist_check()
//{
//  if (dist <= 10)
//  {
//    wait();
//    beep(); 
//    //servo.write(90);
//  }
//  else
//  {
//    noTone(buzzer);
//  }
//}

void setup()
{
  pinMode(mA1, OUTPUT);
  pinMode(mA2, OUTPUT);
  pinMode(mB1, OUTPUT);
  pinMode(mB2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
 // pinMode(2,OUTPUT);
  //digitalWrite(2,LOW);

  servohand.attach(6);
  servohead.attach(3);
  
  servohand.write(90);
  servohead.write(90);
  Serial.begin(9600);
}

void left()
{
  Serial.println("Left");
  digitalWrite(mA1, LOW);
  digitalWrite(mA2, HIGH);
  digitalWrite(mB1, HIGH);
  digitalWrite(mB2, LOW);
  //servo.write(100);
}
void right()
{
  Serial.println("Right");
  digitalWrite(mA1, HIGH);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, HIGH);
  //servo.write(100);
}
void backward()
{
  Serial.println("Backward");
  digitalWrite(mA1, HIGH);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, HIGH);
  digitalWrite(mB2, LOW);
  //servo.write(  100);
}
void forward()
{
  Serial.println("Forward");
  digitalWrite(mA1, LOW);
  digitalWrite(mA2, HIGH);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, HIGH);
  //servo.write(55);
}
void wait()
{
  Serial.println("Wait");
  digitalWrite(mA1, LOW);
  digitalWrite(mA2, LOW);
  digitalWrite(mB1, LOW);
  digitalWrite(mB2, LOW);
  //servo.write(100);
}
//void AI()
//{
//  /*for (long int i = 1; i <= 50; i++)
//    {
//    sensor_check();
//    dist_check();
//    forward();
//
//    if (input == 5)
//    {
//      break;
//    }
//    }
//
//    for (long int i = 1; i <= 10; i++)
//    {
//    sensor_check();
//    dist_check();
//    right();
//
//    if (input == 5)
//    {
//      break;
//    }
//    }
//
//    for (long int i = 1; i <= 5; i++)
//    {
//    sensor_check();
//    dist_check();
//    forward();
//
//    if (input == 5)
//    {
//      break;
//    }
//    }
//
//    for (long int i = 1; i <= 10; i++)
//    {
//    sensor_check();
//    dist_check();
//    right();
//
//    if (input == 5)
//    {
//      break;
//    }
//    }
//    for (long int i = 1; i <= 50; i++)
//    {
//    sensor_check();
//    dist_check();
//    forward();
//
//    if (input == 5)
//    {
//      break;
//    }
//    }
//
//    for (long int i = 1; i <= 10; i++)
//    {
//    sensor_check();
//    dist_check();
//    left();
//
//    if (input == 5)
//    {
//      break;
//    }
//    }
//
//
//    for (long int i = 1; i <= 5; i++)
//    {
//    sensor_check();
//    dist_check();
//    forward();
//    }
//
//
//    for (long int i = 1; i <= 10; i++)
//    {
//    sensor_check();
//    dist_check();
//    left();
//    }
//  */
//  forward();
//  delay(2000);
//  right();
//  delay(400);
//  forward();
//  delay(100);
//  right();
//  delay(1000);
//  forward();
//  delay(3000);
//
//}
void loop()
{
  sensor_check();

  if (dist>=10 && dist <= 20)   //to wave hand
  {
    wait();
   // beep();
    servohand.write(140);
    delay(200);
    servohand.write(40);
    delay(200);
    servohand.write(90);
  }
  else if (dist <= 10)          //to nod head
  {
    wait();
   // beep();
    servohead.write(0);
    delay(100);
    servohead.write(180);
    delay(100);
    servohead.write(90);
  }

  else
  {
    //noTone(buzzer);
sensor_check();
    switch (input)
    {
      case 'S':
        wait();
        break;

      case 'F':
        forward();
        break;

      case 'R':
        right();
        break;

      case 'B':
        backward();
        break;

      case 'L':
        left();
        break;

      case 'X':
        servohand.write(140);
        break;

      case 'x':
        servohand.write(90);
        break;

     case 'V':
        servohead.write(140);
        break;

      case 'v':
        servohead.write(90);
        break;

//      case '7':
//        beep();
//        break;
//
//      case '8':
//        noTone(buzzer);
//        break;

//      case '9':
//        for (int j = 1; j <= 1; j++)
//        {
//          AI();
//          if (input == 5)
//          {
//            break;
//          }
//        }
//        break;

deafult:
        wait();
        break;
    }
  }

}
