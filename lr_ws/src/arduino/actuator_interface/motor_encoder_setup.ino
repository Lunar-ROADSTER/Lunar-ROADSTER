#include "RoboClaw.h"

#define ROBOCLAW_ADDRESS 0x80
#define ROBOCLAW_READ_TIMEOUT_USEC 10000

// For back motors
RoboClaw roboclaw(&Serial1, ROBOCLAW_READ_TIMEOUT_USEC); // Pins 18(TX1) and 19(RX1) on the Due
// For front motors
RoboClaw roboclaw(&Serial2, ROBOCLAW_READ_TIMEOUT_USEC); // Pins 16(TX1) and 17(RX1) on the Due


// Function to move motors and verify encoder feedback
void testMotors() {
  uint8_t status1, status2;   // Status variables for M1 and M2
  bool valid1, valid2;        // Validity flags for M1 and M2

  // Move M1 (movement) motor forward and backward
  // roboclaw.SpeedM1(ROBOCLAW_ADDRESS, 5000); // Set speed for M1
  roboclaw.SpeedM2(ROBOCLAW_ADDRESS, -2000); // Set speed for M2 (steering)
  
  long startTime = millis();
  while (millis() - startTime < 3000) { // Run motors for 3 seconds
    // Read encoder values for M1 and M2
    int32_t encM1 = roboclaw.ReadEncM1(ROBOCLAW_ADDRESS, &status1, &valid1);
    int32_t encM2 = roboclaw.ReadEncM2(ROBOCLAW_ADDRESS, &status2, &valid2);

    // Display M1 (moving) encoder data
    Serial.print("M1 Encoder: ");
    if (valid1) {
      Serial.print(encM1);
      Serial.print(" | Status: ");
      Serial.println(status1, HEX);
    } else {
      Serial.println("Invalid Reading");
    }

    // Display M2 (steering) encoder data
    Serial.print("M2 Encoder: ");
    if (valid2) {
      Serial.print(encM2);
      Serial.print(" | Status: ");
      Serial.println(status2, HEX);
    } else {
      Serial.println("Invalid Reading");
    }

    delay(500); // Update every 500ms
  }

  // Stop the motors after testing
  roboclaw.SpeedM1(ROBOCLAW_ADDRESS, 0);
  roboclaw.SpeedM2(ROBOCLAW_ADDRESS, 0);
  Serial.println("Motors stopped.");
}

// Function to move motors based on serial input
void moveMotors(String command, int moveSpeed, int turnSpeed) {
  // int speed = 4000; // Set a default speed for movement
  // int turnSpeed = 500; // Set a default turn speed for steering
  
  // Stop the motors first
  roboclaw.SpeedM1(ROBOCLAW_ADDRESS, 0);
  roboclaw.SpeedM2(ROBOCLAW_ADDRESS, 0);
  
  // Check the command and act accordingly
  if (command == "forward") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, moveSpeed);  // Move M1 forward
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, 0);      // No steering change
  } 
  else if (command == "backward") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, -moveSpeed); // Move M1 backward
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, 0);      // No steering change
  } 
  else if (command == "left") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, 0);      // No forward/backward movement
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, turnSpeed);  // Turn left
  } 
  else if (command == "right") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, 0);      // No forward/backward movement
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, -turnSpeed); // Turn right
  } 
  else if (command == "forward_left") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, moveSpeed);  // Move forward
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, turnSpeed);  // Turn left
  }
  else if (command == "forward_right") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, moveSpeed);  // Move forward
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, -turnSpeed);  // Turn right
  }
  else if (command == "backward_left") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, -moveSpeed); // Move backward
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, turnSpeed);  // Turn left
  }
  else if (command == "backward_right") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, -moveSpeed); // Move backward
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, -turnSpeed);  // Turn right
  } 
  else if (command == "stop") {
    roboclaw.SpeedM1(ROBOCLAW_ADDRESS, 0);      // Stop M1
    roboclaw.SpeedM2(ROBOCLAW_ADDRESS, 0);      // Stop M2
  } 
  else {
    Serial.println("Invalid Command");
  }

  // Run motors for the specified time and then stop
  long startTime = millis();
  while (millis() - startTime < 3000) {
    // Motors will keep running for the specified duration (moveTime=3s)
    delay(100);  // Small delay to prevent freezing other tasks
  }
  
  // After the time has passed, stop the motors
  roboclaw.SpeedM1(ROBOCLAW_ADDRESS, 0);
  roboclaw.SpeedM2(ROBOCLAW_ADDRESS, 0);
  Serial.println("Motors stopped.");

}

void setup(){
  // Initialize Serial for debugging
  Serial.begin(57600);

  // Initialize RoboClaw
  roboclaw.begin(38400);

  Serial.println("Starting encoder check ...");
}

void loop(){

  // testMotors();

  // Check if there is any data available in Serial input
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read command until newline
    input.trim(); // Remove leading/trailing spaces
    
    // Split the input into command and speeds using space as delimiter
    int firstSpaceIndex = input.indexOf(' ');  // Find the first space (separating command and first speed)
    
    if (firstSpaceIndex == -1) {
      Serial.println("Invalid input. Please use format: <command> <moveSpeed> <steerSpeed>");
      return;  // If there is no space, the input is invalid
    }

    String command = input.substring(0, firstSpaceIndex);  // Extract command
    String speeds = input.substring(firstSpaceIndex + 1);  // Get the rest of the string (speeds)

    int secondSpaceIndex = speeds.indexOf(' ');  // Find the second space (separating moveSpeed and steerSpeed)

    if (secondSpaceIndex == -1) {
      Serial.println("Invalid input. Please use format: <command> <moveSpeed> <steerSpeed>");
      return;  // If there is no second space, the input is invalid
    }

    // Extract the moveSpeed and steerSpeed from the speeds part
    String moveSpeedStr = speeds.substring(0, secondSpaceIndex);
    String steerSpeedStr = speeds.substring(secondSpaceIndex + 1);

    // Convert the strings to integers
    int moveSpeed = moveSpeedStr.toInt();
    int steerSpeed = steerSpeedStr.toInt();

    // Ensure we have valid speed values
    if (moveSpeed == 0 || steerSpeed == 0) {
      Serial.println("Invalid speeds. Please enter valid values.");
      return;
    }

    // Call the moveMotors function with the command and speed values
    moveMotors(command, moveSpeed, steerSpeed);
  }

  delay(1000); // Check for input every 1 second
}