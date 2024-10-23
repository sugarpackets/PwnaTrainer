#include <WiFi.h>
#include <string>

// Function to generate a random SSID
String generate_random_ssid(int length) {
  const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  String ssid = "";
  for (int i = 0; i < length; i++) {
    ssid += charset[random(0, sizeof(charset) - 1)];
  }
  return ssid;
}

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0)); // Initialize random number generator
}

void loop() {
  // Step 1: Generate random SSID
  String ssid = generate_random_ssid(8);  // Generate an 8-character random SSID
  Serial.println("Generated SSID: " + ssid);
  
  // Step 2: Start broadcasting the WiFi network (open/unsecured)
  WiFi.softAP(ssid.c_str());  // Start the Access Point with the generated SSID and no password
  Serial.println("Broadcasting network...");
  
  // Print the IP address of the Access Point
  Serial.print("Access Point IP Address: ");
  Serial.println(WiFi.softAPIP());
  
  // Step 3: Broadcast for 30 seconds
  delay(30000);  // 30 seconds in milliseconds

  // Step 4: Stop the network
  WiFi.softAPdisconnect(true);  // Disable the Access Point
  Serial.println("Network terminated.");

  // Go back to step 1 and repeat
}
