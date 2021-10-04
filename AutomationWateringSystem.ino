// Welcome to Auto Watering System this project is for NodeMCU/ESP8266
// Sensor requirement : ESP8266, YL-69,Relay ,Mini water pump 
// Enjoy The Code !!

int sensorPin = A0;
int sensorValue;
int limit = 700;

void setup()
{
  Serial.begin(115200);
  pinMode(2, OUTPUT); //Digital Pin D4 
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.println("Humidity : ");
  Serial.println(sensorValue);

  if (sensorValue>limit)
  {
    digitalWrite(2, LOW);
  }
  else
  {
    digitalWrite(2, HIGH);
  }
  delay(1000);
}
