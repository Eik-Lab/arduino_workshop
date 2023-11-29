#include <Servo.h>


int pinLB=6; // define pin6 as left back connect with IN1
int pinLF=9; // define pin9 as left forward connect with IN2
int pinRB=10; // define pin10 as right back connect with IN3
int pinRF=11; // define pin11 as right forward connect with IN4
int inputPin = A0; // define ultrasonic receive pin (Echo)
int outputPin =A1; // define ultrasonic send pin(Trig)
int Forward_dist = 0; // initial forward distance
int Right_dist = 0; // initial right distance
int Left_dist = 0; // initial left distance
int directionn = 0;
Servo myservo; // new myservo
int delay_time = 250; // set stable time
int Fgo = 8;  // forward
int Rgo = 6;  // turn right
int Lgo = 4;  // turn left
int Bgo = 2;  // back


void setup()
{
    pinMode(pinLB,OUTPUT);
    pinMode(pinLF,OUTPUT);
    pinMode(pinRB,OUTPUT);
    pinMode(pinRF,OUTPUT);
    pinMode(inputPin, INPUT);
    pinMode(outputPin, OUTPUT);
    myservo.attach(5); // define the servo pin(PWM)
}


void advance(int a) // forward
{
    digitalWrite(pinRB,LOW);
    digitalWrite(pinRF,HIGH);
    digitalWrite(pinLB,LOW);
    digitalWrite(pinLF,HIGH);
    delay(a * 15);
}


void turnR(int d) //turn right
{
    digitalWrite(pinRB,HIGH);
    digitalWrite(pinRF,LOW);
    digitalWrite(pinLB,LOW);
    digitalWrite(pinLF,HIGH);
    delay(d * 50);
}


void turnL(int e) //turn left
{
    digitalWrite(pinRB,LOW);
    digitalWrite(pinRF,HIGH);
    digitalWrite(pinLB,HIGH);
    digitalWrite(pinLF,LOW);
    delay(e * 50);
}


void stopp(int f) //stop
{
    digitalWrite(pinRB,LOW);
    digitalWrite(pinRF,LOW);
    digitalWrite(pinLB,LOW);
    digitalWrite(pinLF,LOW);
    delay(f * 100);
}


void back(int g) //back
{
    digitalWrite(pinRB,HIGH);
    digitalWrite(pinRF,LOW);
    digitalWrite(pinLB,HIGH);
    digitalWrite(pinLF,LOW);
    delay(g * 300);
}


void detection() //test the distance of different direction
{
    int delay_time = 250;
    delay(200);
    ask_pin_F(); // read forward distance
    if(Forward_dist < 10) // if forward distance less then 10
    {
        stopp(1);
        back(2);
    }
    if(Forward_dist < 25) // if forward distance less then 25
    {
        stopp(1);
        ask_pin_L();
        delay(delay_time);
        ask_pin_R();
        delay(delay_time);
        if(Left_dist > Right_dist)  // if left distance more than right distance
        {
            directionn = Lgo;
        }
        if(Left_dist <= Right_dist)  // if left distance is less or equal to right distance
        {
            directionn = Rgo;
        }

        directionn = Bgo;
    }
    else
    {
        directionn = Fgo;
    }
}


void ask_pin_F() // test forward distance
{
    myservo.write(90);
    digitalWrite(outputPin, LOW);
    delayMicroseconds(2);
    digitalWrite(outputPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(outputPin, LOW);
    float Fdistance = pulseIn(inputPin, HIGH);
    Fdistance= Fdistance/58.0;
    Forward_dist = Fdistance;
}


void ask_pin_L() // test left distance
{
    myservo.write(150);
    delay(delay_time);
    digitalWrite(outputPin, LOW);
    delayMicroseconds(2);
    digitalWrite(outputPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(outputPin, LOW);
    float Ldistance = pulseIn(inputPin, HIGH);
    Ldistance= Ldistance/58.0;
    Left_dist = Ldistance;
}


void ask_pin_R() // test right distance
{
    myservo.write(20);
    delay(delay_time);
    digitalWrite(outputPin, LOW);
    delayMicroseconds(2);
    digitalWrite(outputPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(outputPin, LOW);
    float Rdistance = pulseIn(inputPin, HIGH);
    Rdistance= Rdistance/58.0;
    Right_dist = Rdistance;
}


void loop()
{
    myservo.write(90);
    detection();
    if(directionn == 2)
    {
        back(3);
        turnL(2);
    }
    if(directionn == 6)
    {
        back(1);
        turnR(6);
    }
    if(directionn == 4)
    {
        back(1);
        turnL(6);
    }
    if(directionn == 8)
    {
        advance(1);
    }
}
