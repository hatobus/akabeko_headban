
#define stp 2
#define dir 3
#define MS1 4
#define MS2 5
#define EN  6
#define mode1 10
#define mode2 11
#define mode3 12

char user_input;
int select_bpm = 120;
int bpm;
int x;
int y;
int state;

void help()
{
  //Print function list for user selection
  Serial.println("Enter number for control option:");
  //80 rotate at 60 sec
  //1 rotation is 200 step
  //1 step is 1.8 angle
  Serial.println("1. 30sec 80rotate");
  Serial.println("2. 30sec 116rotate");
  Serial.println("3. 30sec 200rotate");
  Serial.println("6. BPM");
}

void setup() {
  // put your setup code here, to run once:
  pinMode(stp, OUTPUT);  pinMode(dir, OUTPUT);  pinMode(MS1, OUTPUT);  pinMode(MS2, OUTPUT);  pinMode(EN, OUTPUT);
  pinMode(mode1,OUTPUT);  pinMode(mode2,OUTPUT);  pinMode(mode3,OUTPUT);
  resetEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Begin motor control");
  Serial.println();
  help();  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
      digitalWrite(EN, LOW); //Pull enable pin low to allow motor control
      if (digitalRead(mode1)==1){
          Stepselected(80);
      }
      else if(digitalRead(mode2)==1){
          Stepselected(116);
      }
      else if(digitalRead(mode3)==1){
          Stepselected(145);
      }
      else{
        Serial.println("0");
        help();
      }
  }  
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
