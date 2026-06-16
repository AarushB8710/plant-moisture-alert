// Plant Moisture Alert System
// By Aarush | Grade 10 Engineering Project

const int sensorPower = 7; // Powers the sensor
const int sensorPin = A0;   // Reads the moisture value
const int greenLED = 8;     // OK status
const int redLED = 9;       // Alert status

// Threshold set to 200 based on your calibration (Dry ~0, Wet ~400)
int threshold = 200; 

void setup() {
  pinMode(sensorPower, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  // Start with sensor off to prevent corrosion
  digitalWrite(sensorPower, LOW);
  
  Serial.begin(9600);
  Serial.println("System Online - Dubai Urban Farming Project");
}

void loop() {
  int moisture = readSensor();
  
  Serial.print("Moisture Level: ");
  Serial.print(moisture);

  // LOGIC: If moisture is below 200, it is DRY.
  if (moisture < threshold) {
    digitalWrite(redLED, HIGH);   // Red ON
    digitalWrite(greenLED, LOW);  // Green OFF
    Serial.println(" -> STATUS: DRY (Needs Water)");
  } 
  // If moisture is 200 or above, it is MOIST.
  else {
    digitalWrite(redLED, LOW);    // Red OFF
    digitalWrite(greenLED, HIGH); // Green ON
    Serial.println(" -> STATUS: MOIST (Soil OK)");
  }

  delay(3000); // Wait 3 seconds before next reading
}

// Function to power sensor, read it, and turn it off
int readSensor() {
  digitalWrite(sensorPower, HIGH); // Turn sensor on
  delay(20);                       // Wait for stable voltage
  int val = analogRead(sensorPin); // Read the analog value
  digitalWrite(sensorPower, LOW);  // Turn sensor off
  return val;
}
