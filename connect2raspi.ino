// Connecting Raspberry pi and Arduino
// GPIO to connect directoly each other
// if raspberry pi GPIO pin HIGH
// Arduino INPUT GPIO order.

#define LEDPIN 12
#define Buttonin 5

void setup() {
  // put your setup code here, to run once:
  
  pinMode(LEDPIN, OUTPUT);
  pinMode(Buttonin,INPUT);

  Serial.begin(9600);

  // GPIO 5 pin is input Raspberry pi's GPIO pin
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Buttonin) == 1){
    digitalWrite(LEDPIN,HIGH);
  }

  else{
    digitalWrite(LEDPIN,LOW);
  }
  Serial.println(digitalRead(5));
  delay(100);
}
