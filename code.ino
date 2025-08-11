const int tempPin = A0;            // TEMP sensor data pin
const int pirPin = 2;              // PIR motion sensor pin
const int fanRelayPin = 4;         // Relay (LED) for fan
const int lightRelayPin = 3;       // Relay (LED) for light

// Motion tracking variables
unsigned long motionStartTime = 0;
bool lightOn = false;

void setup() {
  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(fanRelayPin, OUTPUT);
  pinMode(lightRelayPin, OUTPUT);

  digitalWrite(fanRelayPin, LOW);   // Fan off initially
  digitalWrite(lightRelayPin, LOW); // Light off initially
}

void loop() {
  float temperature = analogRead(tempPin);

  // Temperature control
  if (!isnan(temperature)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    if (temperature > 30.0) {
      digitalWrite(fanRelayPin, HIGH);  // Turn on fan
    } else {
      digitalWrite(fanRelayPin, LOW);   // Turn off fan
    }
  }

  // Motion detection
  int motionDetected = digitalRead(pirPin);

  if (motionDetected == HIGH && !lightOn) {
    Serial.println("Motion Detected! Light ON.");
    digitalWrite(lightRelayPin, HIGH);
    motionStartTime = millis();
    lightOn = true;
  }

  // Auto turn-off after 30 seconds
  if (lightOn && (millis() - motionStartTime >= 30000)) {
    digitalWrite(lightRelayPin, LOW);
    Serial.println("30 seconds passed. Light OFF.");
    lightOn = false;
  }

  delay(500);
}
