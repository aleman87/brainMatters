#define BUTTON_NUM 6
#define LED_NUM 10
//score points per button
const int scorePoints[BUTTON_NUM]={10,20,30,40,50,100};

//count of the score
int count=0;

// set pin numbers:
const int buttonPin[BUTTON_NUM]={14,15,16,17,18,19};

// the current reading from the input pin
int buttonState[BUTTON_NUM];

// the previous reading from the input pin
int lastButtonState[BUTTON_NUM]={LOW,LOW,LOW,LOW,LOW,LOW};

//LED stuff
//const int ledPin1 = 8;      // the number of the LED pin
const int ledPins[LED_NUM]={2,3,4,5,6,7,8,9,10,11};

// Variables will change:
//int ledState = HIGH;         // the current state of the output pin


// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  //setup buttons as input
  for (int i=0; i<BUTTON_NUM;i++)
  {
    pinMode(buttonPin[i],INPUT);
    }
   //setup LEDs as output
  for (int i=0;i<LED_NUM;i++)
  {
    pinMode(ledPins[i],OUTPUT);
    }
  //pinMode(ledPin1, OUTPUT);
 Serial.begin(9600);
  // set initial LED state
  //digitalWrite(ledPin1, ledState);
}

void loop() {
  int reading[BUTTON_NUM];
  //map the result from 0 t0 100 to the number of LEDs available
  int ledLevel=map(count,0,100,0,LED_NUM);
  
  for (int i=0;i<BUTTON_NUM;i++)
  {
    reading[i]=digitalRead(buttonPin[i]);
    if(reading[i] !=lastButtonState[i])
    {
      lastDebounceTime=millis();
      }
    }

  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
for (int i=0;i<BUTTON_NUM;i++)
{
  if(reading[i]!=buttonState[i])
  {
    buttonState[i]=reading[i];
    if(buttonState[i]==HIGH)
    {
      count+=scorePoints[i];
      Serial.println(count);
      //turn on all LEDs if the count is at 100
      if(count>=100)
      {
        for(int j;j<LED_NUM;j++)
        {
          digitalWrite(ledPins[j],HIGH);
          }
        }
        //otherwise check to see which ones to turn on
        else
        {
      //determine how many LEDs to turn on after the score
      for (int thisLED=0;thisLED<LED_NUM;thisLED)
      {
        //if the count is less than the LEDs value then turn on LED
        if(thisLED<ledLevel)
        {
          digitalWrite(ledPins[thisLED],HIGH);
          }
          //turn off all the LEDs that are higher than the LED
          else
          {
            digitalWrite(ledPins[thisLED],LOW);
            }
        }
        }
      }
    if (count>=100)
    {
      count=0;
      for(int j=0;j<LED_NUM;j++)
        {
          digitalWrite(ledPins[j],LOW);
          }
      }
    }
  }
   
  }

  // set the LED:
  //digitalWrite(ledPin1, ledState);
for (int i=0;i<BUTTON_NUM;i++)
{
  lastButtonState[i]=reading[i];
  }
  
}//end of void loop

