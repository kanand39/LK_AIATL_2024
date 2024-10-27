/*
 * HC-SR04 example sketch
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 */

const int trigPin = 2;
const int echoPin = 4;
const int ledPin = 13;  // LED pin

float duration, distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledPin, OUTPUT); // Set LED pin as output
    Serial.begin(9600);
}

void loop() {
    // Ultrasonic sensor part
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.0343) / 2;

    Serial.print("Distance: ");
    Serial.println(distance);

    // Check if distance is less than 10 cm
    if (distance < 10) {
        digitalWrite(ledPin, HIGH); // Turn LED on for ultrasonic detection
    } else {
        digitalWrite(ledPin, LOW); // Turn LED off
    }

    // Serial communication part
    if (Serial.available() > 0) {  // Check if there's data from Python
        String input = Serial.readString();  // Read the incoming message

        // Check for specific keywords in the input string
        if (input.indexOf("person") >= 0 || input.indexOf("persons") >= 0 || 
            input.indexOf("chair") >= 0 || input.indexOf("chairs") >= 0 || 
            input.indexOf("backpack") >= 0 || input.indexOf("backpacks") >= 0) {
            digitalWrite(ledPin, HIGH);  // Turn on LED for specific keywords
            delay(500);  // Keep LED on for 500 ms
            digitalWrite(ledPin, LOW);  // Turn off LED
        }
    }

    delay(100);
}