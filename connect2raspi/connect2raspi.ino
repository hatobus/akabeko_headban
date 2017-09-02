// Connecting Raspberry pi and Arduino
// GPIO to connect directoly each other
// if raspberry pi GPIO pin HIGH
// Arduino INPUT GPIO order.

#define Buttonin 10
#define stp 2
#define dir 3
#define MS1 4
#define MS2 5
#define EN  6

char user_input;
int select_bpm = 120;
int bpm;
int x;
int y;
int state;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(Buttonin,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  resetEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.println("Begin motor control");
  Serial.println();  

  // GPIO 5 pin is input Raspberry pi's GPIO pin
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Buttonin) == 1){
    Stepselected(80);
  }
  Serial.println(digitalRead(5));
  delay(100);
}

void Stepselected(int select_bpm)
{
  double t=0;
  int l = select_bpm * 200;
  double d = 30000/(2*(double)l);
  Serial.println("BPM banging");
  if(d>1){
    for(x= 1; x<l; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delay(d);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(d);
      t=t+2*d;
    }
  }

  else{
    d = d*1000;
    Serial.println("us");
    for(x= 1; x<100; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delayMicroseconds(650);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delayMicroseconds(650);
      t=t+2*d;
    }

    Serial.println("hairyu");
    
    for(x= 1; x<l; x++)  //Loop the forward stepping enough times for motion to be visible
    {
      digitalWrite(stp,HIGH); //Trigger one step forward
      delayMicroseconds(d);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delayMicroseconds(d);
      t=t+2*d;
    }
  }
  
  resetEDPins();
}


void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
}
