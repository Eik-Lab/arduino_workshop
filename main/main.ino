int neg1 = 13;
int neg2 = 12;
int neg3 = 11;
int neg4 = 10;
int neg5 = 9;
int neg6 = 8; 
int neg7 = 7;
int neg8 = 6;
int neg9 = 5;
//"neg1" is connected to the 13th digital pin of arduino
//"'neg2" is connected to the 12th digital pin of arduino
//"neg3" is connected to the 11th digital pin of arduino
//"neg4" is connected to the 10th digital pin of arduino
//"neg5" is connected to the 9th digital pin of arduino
//"neg6" is connected to the 8th digital pin of arduino
//"neg7" is connected to the 7th digital pin of arduino
//"neg8" is connected to the 6th digital pin of arduino
//"negg" is connected to the 5th digital pin of arduino
int pos1 = 4;
int pos2 = 3;
int pos3 = 2;
//"pos1" is connected to the 4th digital pin of arduino
//"pos2" is connected to the 3rd digital pin of arduino
//"'pos3" is connected to the 2nd digital pin of arduino
int delay_time=100, j=0;
// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
  pinMode(neg1, OUTPUT) ;
  pinMode (neg2, OUTPUT) ;
  pinMode(neg3, OUTPUT) ;
  pinMode (neg4, OUTPUT) ;
  pinMode(neg5, OUTPUT) ;
  pinMode (neg6, OUTPUT) ;
  pinMode(neg7, OUTPUT) ;
  pinMode (neg8, OUTPUT) ;
  pinMode(neg9, OUTPUT) ;
  pinMode(pos1, OUTPUT) ;
  pinMode (pos2, OUTPUT) ;
  pinMode (pos3, OUTPUT) ;
}


// the loop routine runs over and over again forever:
void loop() {
for(j=0;j<6;j++){
  digitalWrite(pos1, HIGH) ;
  digitalWrite(pos2, HIGH) ;
  digitalWrite(pos3, LOW) ;
  digitalWrite(neg1, LOW) ;
  digitalWrite(neg2, LOW) ;
  digitalWrite(neg3, HIGH) ;
  digitalWrite(neg4, LOW) ;
  digitalWrite(neg5, LOW) ;
  digitalWrite (neg6, HIGH) ;
  digitalWrite(neg7, LOW) ;
  digitalWrite(neg8, LOW) ;
  digitalWrite(neg9, HIGH) ;
  delay (150) ;
}
}