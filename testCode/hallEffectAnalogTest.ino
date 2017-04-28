const int hallPin=A2;
const int ledPin=13;
const int readings=25;

void setup() {
  pinMode(hallPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sum = 0;
  int value;
  int avg;
  for(int i = 0; i < readings; i++){//average over a few readings to get rid of spikes
      value = analogRead(hallPin);
      sum += value;
  }
  avg=sum/readings;
  if (avg<250){//light LED once level falls below threshold
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  Serial.println(avg);//print to serial to see on plotter or monitor
  delay(50);
}
