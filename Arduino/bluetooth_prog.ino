// An LED is connected to pin 4
// LED glows when character '1' is received from HC-05 bluetooth module
//mightyIT app used in smartphone to connect to HC-05 and send signals

void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  Serial.begin(38400); // Fix comm rate of the Bluetooth module
  int inp = 0;
}
void loop() {
  if(Serial.available() > 0){ // input check at serial port
    inp = Serial.read(); // read data if present
 }
 if (inp == '0') {
  digitalWrite(4, LOW); // Turn LED OFF
  Serial.println("LED: OFF");
  inp = 0; // set inp to not execute above lines again as the loop is infinite
 }
 else if (inp == '1') {
  digitalWrite(4, HIGH);
  Serial.println("LED: ON");;
  inp = 0;
 } 
}