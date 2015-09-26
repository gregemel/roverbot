

int trigPin = 13;
int echoPin = 12;
long duration, distance = 0;


void PingSetup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void RangeGet()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if(debug == 1)
  {
    if (distance >= 500 || distance <= 0){
      Serial.println("Out of range");
    }
    else {
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
    delay(500);
  }
}

