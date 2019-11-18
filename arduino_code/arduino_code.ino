/**
  Car Bluetooth Arduino Controller
  
  Author: Juan Manuel Young Hoyos.
*/
#include <SoftwareSerial.h>

// You can change the pins
#define BLUETOOTH_TX 50
#define BLUETOOTH_TD 51

#define MOTOR_1_A 22
#define MOTOR_1_B 23
#define MOTOR_1_PWM 24

#define MOTOR_2_A 27
#define MOTOR_2_B 28
#define MOTOR_2_PWM 29

const int state_0 = 0;
const int state_1 = 1;
const int state_2 = 2;
const int state_3 = 3;
const int state_4 = 4;

long int data;
SoftwareSerial Blue(BLUETOOTH_TX, BLUETOOTH_TD);

void stopCar() {
  digitalWrite(MOTOR_1_A, LOW);
  digitalWrite(MOTOR_1_B, LOW);
  analogWrite(MOTOR_1_PWM, 0);

  digitalWrite(MOTOR_2_A, LOW);
  digitalWrite(MOTOR_2_B, LOW);
  analogWrite(MOTOR_2_PWM, 0);
}

void accelerate() {
  digitalWrite(MOTOR_1_A, LOW);
  digitalWrite(MOTOR_1_B, HIGH);
  analogWrite(MOTOR_1_PWM, 2000);

  digitalWrite(MOTOR_2_A, LOW);
  digitalWrite(MOTOR_2_B, LOW);
  analogWrite(MOTOR_2_PWM, 0);
}

void reverse() {
  digitalWrite(MOTOR_1_A, HIGH);
  digitalWrite(MOTOR_1_B, LOW);
  analogWrite(MOTOR_1_PWM, 2000);

  digitalWrite(MOTOR_2_A, LOW);
  digitalWrite(MOTOR_2_B, LOW);
  analogWrite(MOTOR_2_PWM, 0);
}

void turnRight() {
  digitalWrite(MOTOR_1_A, LOW);
  digitalWrite(MOTOR_1_B, HIGH);
  analogWrite(MOTOR_1_PWM, 2000);

  digitalWrite(MOTOR_2_A, HIGH);
  digitalWrite(MOTOR_2_B, LOW);
  analogWrite(MOTOR_2_PWM, 2000);
}

void turnLeft() {
  digitalWrite(MOTOR_1_A, LOW);
  digitalWrite(MOTOR_1_B, HIGH);
  analogWrite(MOTOR_1_PWM, 800);

  digitalWrite(MOTOR_2_A, LOW);
  digitalWrite(MOTOR_2_B, HIGH);
  analogWrite(MOTOR_2_PWM, 800);
}

void setup() {

  pinMode(MOTOR_1_A, OUTPUT);
  pinMode(MOTOR_1_B, OUTPUT);
  pinMode(MOTOR_1_PWM, OUTPUT);
  
  pinMode(MOTOR_2_A, OUTPUT);
  pinMode(MOTOR_2_B, OUTPUT);
  pinMode(MOTOR_2_PWM, OUTPUT);
  
  stopCar();

  Blue.begin(9600);
}

void loop() {
  while (Blue.available() == 0);

  if (Blue.available() > 0)
    data = Blue.parseInt();
  
  switch(data) {
    case state_0:
      stopCar();
      break;
    case state_1:
      accelerate();
      break;
    case state_2:
      reverse();
      break;
    case state_3:
      turnRight();
      break;
    case state_4:
      turnLeft();
      break;
    default:
      stopCar();
      break;  
  }
}
