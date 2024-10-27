const int trigPin = 2;
const int echoPin = 4;
const int ledPin = 13;
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, LOW);
  distance = (duration * 0.0343) / 2;

  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    if (input == "Obstacle detected" || distance < 10) {
      digitalWrite(ledPin, HIGH);
      delay(1000);  // LED on for 1 second
      digitalWrite(ledPin, LOW);
    }
  }

  // Distance detection code (if needed)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
