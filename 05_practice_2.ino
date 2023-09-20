#define PIN_LED 7
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200); //Initialize serial port
  while (!Serial) {
    ; //wait for serial port to connect.
  }
  Serial.println("Hello World!");
  count=toggle=0;
  digitalWrite(PIN_LED, toggle); //turn off LED.
}


void loop() {
  Serial.println(++count);
  delay(1000);
  toggle=toggle_state(toggle);
  digitalWrite(PIN_LED, toggle);
  
  for(int i=0; i<=11; i++){
    toggle=toggle_state(toggle); 
    digitalWrite(PIN_LED, toggle); //update LED status.
    delay(100); //write for 1,000 milliseconds
  }
  while(1) {}
}

unsigned int toggle_state(unsigned int toggle) {
  toggle++;
  return toggle%2;
}
