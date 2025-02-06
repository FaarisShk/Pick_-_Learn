const int r1Pin = 2;
const int ledr1Pin = 7;
const int r2Pin = 3;
const int ledr2Pin = 8;
const int r3Pin = 4;
const int ledr3Pin = 9;

//Code for more two sensors
//const int r4Pin = 5;
//const int ledr4Pin = 10;
//const int r5Pin = 6;
//const int ledr5Pin = 11;


void setup() {  
  
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600); 
  // Set sensor pins as inputs and LED pins as outputs
  pinMode(r1Pin, INPUT);
  pinMode(r2Pin, INPUT);
  pinMode(r3Pin, INPUT);
  //pinMode(r4Pin, INPUT);
  //pinMode(r5Pin, INPUT);
  pinMode(ledr1Pin, OUTPUT);
  pinMode(ledr2Pin, OUTPUT);
  pinMode(ledr3Pin, OUTPUT);
  //pinMode(ledr4Pin, OUTPUT);
  //pinMode(ledr5Pin, OUTPUT);
} 

void loop() {
  // Main Loop
  int sensor1Value = digitalRead(r1Pin);
  int sensor2Value = digitalRead(r2Pin);
  int sensor3Value = digitalRead(r3Pin);
  //int sensor4Value = digitalRead(r4Pin);
  //int sensor5Value = digitalRead(r5Pin);

  bool allSensorsClosed = (sensor1Value == LOW) && (sensor2Value == LOW) && (sensor3Value == LOW);// && (sensor4Value == LOW) && (sensor5Value == LOW);
  bool allSensorsOpen = (sensor1Value == HIGH) && (sensor2Value == HIGH) && (sensor3Value == HIGH); //&& (sensor4Value == LOW) && (sensor5Value == LOW);
  bool twoSensorsOpen = ((sensor1Value == HIGH) && (sensor2Value == HIGH));
  bool twSensorsOpen = ((sensor1Value == HIGH) && (sensor3Value == HIGH));
  bool toSensorsOpen = ((sensor2Value == HIGH) && (sensor3Value == HIGH));
  
  //bool otSensorsOpen = ((sensor4Value == HIGH) && (sensor5Value == HIGH));
  //bool ooSensorsOpen = ((sensor3Value == HIGH) && (sensor5Value == HIGH));

  //LED Control
  // Control LED 1
  if (sensor1Value == LOW) {
    digitalWrite(ledr1Pin, HIGH);  // Turn on LED 1
  } else {
    digitalWrite(ledr1Pin, LOW);   // Turn off LED 1
  //  Serial.println("1");  // Print "1" for LED 1 OFF
  }
  
  // Control LED 2
  if (sensor2Value == LOW) {
    digitalWrite(ledr2Pin, HIGH);  // Turn on LED 2
  } else {
    digitalWrite(ledr2Pin, LOW);   // Turn off LED 2
  //  Serial.println("2");  // Print "2" for LED 2 OFF
  }

  // Control LED 3
  if (sensor3Value == LOW) {
    digitalWrite(ledr3Pin, HIGH);  // Turn on LED 3
  } else {
    digitalWrite(ledr3Pin, LOW);   // Turn off LED 3
   // Serial.println("3");  // Print "3" for LED 3 OFF
  }

  // Control LED 4
  //if (sensor4Value == LOW) {
  //  digitalWrite(ledr4Pin, HIGH);  // Turn on LED 4
 // } else {
   // digitalWrite(ledr4Pin, LOW);   // Turn off LED 4
   // Serial.println("4");  // Print "4" for LED 4 OFF
  //}

  // Control LED 5
  //if (sensor5Value == LOW) {
    //digitalWrite(ledr5Pin, HIGH);  // Turn on LED 5
  //} else {
    //digitalWrite(ledr5Pin, LOW);   // Turn off LED 5
   // Serial.println("5");  // Print "5" for LED 5 OFF
  //}

  // Serial Communication
  if (allSensorsClosed) {
    Serial.println("0");  // Print "0" if all sensors are closed
  } else if (allSensorsOpen) {
    Serial.println("9");  // Print "9" if all sensors are open
  } else if (twoSensorsOpen) {
    Serial.println("8");  // Print "8" if sensor "1" and sensor "2" are open
  } else if (twSensorsOpen) {
    Serial.println("7");  // Print "7" if sensor "1" and sensor "3" are open
  } else if (toSensorsOpen) {
    Serial.println("6");  // Print "6" if sensor "2" and sensor "3" are open
  //} else if (otSensorsOpen) {
    //Serial.println("5"); // Print "5" if two sensors are open
  //} else if (ooSensorsOpen) {
    //Serial.println("6"); // Print "6" if two sensors are open
  } else {
    if (sensor1Value == HIGH) Serial.println("1");   // Print "1" if sensor 1 is open
    if (sensor2Value == HIGH) Serial.println("2");   // Print "2" if sensor 2 is open
    if (sensor3Value == HIGH) Serial.println("3");   // Print "3" if sensor 3 is open
    //if (sensor4Value == HIGH) Serial.println("4"); // Print "4" if sensor 4 is open
    //if (sensor5Value == HIGH) Serial.println("5"); // Print "5" if sensor 5 is open
  }  
  
 // Delay for 500 milliseconds before the next loop iteration
  delay(500);
}
