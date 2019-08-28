#define buttonPin 12        // analog input pin to use as a digital input
#define ledPin1 8          // digital output pin for LED 1
#define ledPin2 9          // digital output pin for LED 2
#define ledPin3 10          // digital output pin for LED 3
#define ledPin4 11          // digital output pin for LED 4

// LED variables
boolean ledVal1 = false;    // state of LED 1
boolean ledVal2 = false;    // state of LED 2
boolean ledVal3 = false;    // state of LED 3
boolean ledVal4 = false;    // state of LED 4

int debounce = 20;          
int DCgap = 250;            
int holdTime = 1000;        
int longHoldTime = 3000;    
boolean buttonVal = HIGH;   
boolean buttonLast = HIGH;  
boolean DCwaiting = false;  
boolean DConUp = false;     
boolean singleOK = true;    
long downTime = -1;        
long upTime = -1;          
boolean ignoreUp = false; 
boolean waitForUp = false;       
boolean holdEventPast = false;  
boolean longHoldEventPast = false;

//=================================================

void setup() {
   // Set button input pin
   pinMode(buttonPin, INPUT);
   digitalWrite(buttonPin, HIGH );
   // Set LED output pins
   pinMode(ledPin1, OUTPUT);
   digitalWrite(ledPin1, ledVal1);
   pinMode(ledPin2, OUTPUT);
   digitalWrite(ledPin2, ledVal2);
   pinMode(ledPin3, OUTPUT);    
   digitalWrite(ledPin3, ledVal3);
   pinMode(ledPin4, OUTPUT);    
   digitalWrite(ledPin4, ledVal4);
   Serial.begin(9600);
}

void loop() {
   // Get button event and act accordingly
   int b = checkButton();
   if (b == 1) clickEvent();
   if (b == 2) doubleClickEvent();
   if (b == 3) holdEvent();
   if (b == 4) longHoldEvent();
}

//=================================================
// Events to trigger

void clickEvent() {
   /*ledVal1 = !ledVal1;
   digitalWrite(ledPin1, ledVal1);*/
   Serial.println("clickEvent");
}
void doubleClickEvent() {
   /*ledVal2 = !ledVal2;
   digitalWrite(ledPin2, ledVal2);*/
   Serial.println("doubleClickEvent");
}
void holdEvent() {
   /*ledVal3 = !ledVal3;
   digitalWrite(ledPin3, ledVal3);*/
   Serial.println("holdEvent");
}
void longHoldEvent() {
   /*ledVal4 = !ledVal4;
   digitalWrite(ledPin4, ledVal4);*/
   Serial.println("longHoldEvent");
}






int checkButton() {    
   int event = 0;
   buttonVal = digitalRead(buttonPin);
   // Button pressed down
   if (buttonVal == LOW && buttonLast == HIGH && (millis() - upTime) > debounce)
   {
       downTime = millis();
       ignoreUp = false;
       waitForUp = false;
       singleOK = true;
       holdEventPast = false;
       longHoldEventPast = false;
       if ((millis()-upTime) < DCgap && DConUp == false && DCwaiting == true)  DConUp = true;
       else  DConUp = false;
       DCwaiting = false;
   }
   // Button released
   else if (buttonVal == HIGH && buttonLast == LOW && (millis() - downTime) > debounce)
   {        
       if (not ignoreUp)
       {
           upTime = millis();
           if (DConUp == false) DCwaiting = true;
           else
           {
               event = 2;
               DConUp = false;
               DCwaiting = false;
               singleOK = false;
           }
       }
   }
   // Test for normal click event: DCgap expired
   if ( buttonVal == HIGH && (millis()-upTime) >= DCgap && DCwaiting == true && DConUp == false && singleOK == true && event != 2)
   {
       event = 1;
       DCwaiting = false;
   }
   // Test for hold
   if (buttonVal == LOW && (millis() - downTime) >= holdTime) {
       // Trigger "normal" hold
       if (not holdEventPast)
       {
           event = 3;
           waitForUp = true;
           ignoreUp = true;
           DConUp = false;
           DCwaiting = false;
           //downTime = millis();
           holdEventPast = true;
       }
       // Trigger "long" hold
       if ((millis() - downTime) >= longHoldTime)
       {
           if (not longHoldEventPast)
           {
               event = 4;
               longHoldEventPast = true;
           }
       }
   }
   buttonLast = buttonVal;
   return event;
}

