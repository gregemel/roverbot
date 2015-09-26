// Rover Drive Code - Keyes L298 Dual H-Bridge Motor Sheild
// version 0.0.1   Greg Emel  2014-02-26  Setup and Forward drive

//motor a
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 9;

//motor b
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 10;

int speed = 250;

float leftSlowdown = 0.9f;
float rightSlowdown = 1.0f;


//drive motors
void DriveSetup()
{
  Log("**Drive A Setup**");
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  
  Log("**Drive B Setup**");
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);

  Log("**Drive Setup Complete**");
}


void DriveStop()
{
  Log("**MOVE STOP***");
 
  analogWrite(speedPinA, 0);
  analogWrite(speedPinB, 0);
}

void DriveForward()
{
  Log("Forward...");
      
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  
  analogWrite(speedPinA, speed * leftSlowdown);
  analogWrite(speedPinB, speed * rightSlowdown);
}

void DriveAvoid()
{
  if(debug == 1)
  {
    Serial.println("**MOVE AWAY***");
  }
  
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  
  analogWrite(speedPinA, speed * 0.3f);
  analogWrite(speedPinB, speed);
}


