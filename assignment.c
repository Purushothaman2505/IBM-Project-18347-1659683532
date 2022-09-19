#include <Servo.h>

Int output1Value = 0;
Int sen1Value = 0;
Int sen2Value = 0;
Int const gas_sensor = A1;
Int const LDR = A0;
Int limit = 400;

Long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  Return pulseIn(echoPin, HIGH);
}

Servo servo_7;

Void setup()
{
   Serial.begin(9600);	
  pinMode(A0, INPUT);		
  pinMode(A1,INPUT);      	 
  pinMode(13, OUTPUT);		
  servo_7.attach(7, 500, 2500); 

  pinMode(8,OUTPUT);     
  pinMode(9, INPUT);		
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);		
  pinMode(3, OUTPUT);		
 }
Void loop()
    Int val1 = analogRead(LDR);
  If (val1 > 500) 
  	{
    	digitalWrite(13, LOW);
    Serial.print(“Bulb ON = “);
    Serial.print(val1);
  	} 
  Else 
  	{
    	digitalWrite(13, HIGH);
     Serial.print(“Bulb OFF = “);
    Serial.print(val1);
  	}
  Sen2Value = digitalRead(9);
  If (sen2Value == 0) 
  	{
    	digitalWrite(10, LOW); 
    	digitalWrite(4, HIGH); 
    	digitalWrite(3, LOW); 
    Serial.print(“     || NO Motion Detected    “ );
  	}
 
  If (sen2Value == 1) 
  	{
    	digitalWrite(10, HIGH);
    delay(3000);
    	digitalWrite(4, LOW); 
    	digitalWrite(3, HIGH);
     Serial.print(“ 	   || Motion Detected!      “ );
  	}
  Delay(300);
  
Int val = analogRead(gas_sensor);      
  Serial.print(“|| Gas Sensor Value = “);
  Serial.print(val);			
Val = map(val, 300, 750, 0, 100); 
  If (val > limit)
  	{
    	Tone(8, 650);
  	}
 	Delay(300);
 	noTone(8);
  Sen1Value = 0.01723 * readUltrasonicDistance(6, 6);

  If (sen1Value < 100) 
  	{
    	Servo_7.write(90);
    Serial.print(“ 	  || Door Open!  ; Distance = “);
    Serial.print(sen1Value);
   Serial.print(“\n”);
 
  	} 
  Else 
  	{
    	Servo_7.write(0);
    Serial.print(“ 	  || Door Closed! ; Distance =  “);
    Serial.print(sen1Value);
    Serial.print(“\n”);
  }
  Delay(10); 
}