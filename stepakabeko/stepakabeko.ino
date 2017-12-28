
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
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  resetEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Begin motor control");
  Serial.println();
  help();  
}
void loop() {
  digitalWrite(EN, LOW); //Pull enable pin low to allow motor control
  Stepselected(140);
//  delay(300000);

  delay(10000);
//  Stepselected(40);
//  delay(3000);  
}
void loop77() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
      user_input = Serial.read(); //Read user input and trigger appropriate function
      digitalWrite(EN, LOW); //Pull enable pin low to allow motor control
      Serial.print("Choose:");
      Serial.println(user_input);
      if (user_input =='1'){
          Stepselected(20);
      }
      else if(user_input =='2'){
          Stepselected(116);
      }
      else if(user_input =='3'){
          Stepselected(150);
      }
      else if(user_input =='6'){
        //select_bpm = Serial.read();
        //bpm = select_bpm;
        //int A = Serial.parseInt();
        //select_bpm = select_bpm - 0x30;
        //StepMode(select_bpm);
        Serial.print("BPM:");
        Serial.print(select_bpm);
        Serial.println();
        Stepselected(select_bpm);
      }
      else if(user_input =='h')
      {
        help();
      }
      else{
        Serial.println("Invalid option entered.");
        help();
      }
      resetEDPins();
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
      delayMicroseconds(1000);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delayMicroseconds(1000);
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
  
  Serial.print("Time = ");
  Serial.print(t);
  Serial.println(" ms");
  Serial.print("Delay = ");
  Serial.print(d);
  Serial.println(" ms");
  Serial.print("Loop = ");
  Serial.print(l);
  Serial.println(" step");
  Serial.println("Enter new option:");
  Serial.println();
}


void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
}
