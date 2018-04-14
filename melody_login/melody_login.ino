#define trigPin 8
#define echoPin 7

//Pin connected to ST_CP of 74HC595
int latchPin = 6;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

byte leds = 0;
int currentLED = 0;

void setup()
{

  /* add setup code here */
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT); //Pin, do którego pod³¹czymy trig jako wyjœcie
	pinMode(echoPin, INPUT); //a echo, jako wejœcie

	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);

}	


void loop()
{
	int odleglosc = zmierzOdleglosc();
	Serial.println(odleglosc);
	//Serial.println(" cm");

	int prawidlowaOdleglosc;

	leds = 0;

	//tone(A2, odleglosc, 0);

	/*
	if (currentLED == 7)
	{
		currentLED = 0;
	}
	else
	{
		currentLED++;
	}
	
	*/

	//Serial.println(currentLED);
	
	if (odleglosc < 62)
	{
	

			if (odleglosc < 8)
			{
				bitSet(leds, 0);
			}
			else if (odleglosc < 16)
			{
				bitSet(leds, 0);
				bitSet(leds, 1);
			}
			else if (odleglosc < 24)
			{
				bitSet(leds, 0);
				bitSet(leds, 1);
				bitSet(leds, 2);
			}
			else if (odleglosc < 32)
			{
				bitSet(leds, 0);
				bitSet(leds, 1);
				bitSet(leds, 2);
				bitSet(leds, 3);
			}
			else if (odleglosc < 40)
			{
				bitSet(leds, 0);
				bitSet(leds, 1);
				bitSet(leds, 2);
				bitSet(leds, 3);
				bitSet(leds, 4);
			}
			else if (odleglosc < 48)
			{
				bitSet(leds, 0);
				bitSet(leds, 1);
				bitSet(leds, 2);
				bitSet(leds, 3);
				bitSet(leds, 4);
				bitSet(leds, 5);
			}
			else if (odleglosc < 56)
			{
				bitSet(leds, 0);
				bitSet(leds, 1);
				bitSet(leds, 2);
				bitSet(leds, 3);
				bitSet(leds, 4);
				bitSet(leds, 5);
				bitSet(leds, 6);
			}
			else
			{
				bitSet(leds, 0);
				bitSet(leds, 1);
				bitSet(leds, 2);
				bitSet(leds, 3);
				bitSet(leds, 4);
				bitSet(leds, 5);
				bitSet(leds, 6);
				bitSet(leds, 7);
			}
			
			/*
			if (odleglosc <= 20)
			{
				Serial.println("cH");
			}
			else if (20 < odleglosc <= 40)
			{
				Serial.println("f");
			}
			else if (odleglosc > 40)
			{
				Serial.println("a");
			}
		*/
	}

	


		//leds = (odleglosc / 9)+0;
		//Serial.println(leds);

		//bitSet(leds, currentLED);
		//bitSet(leds, currentLED + 1);

		digitalWrite(latchPin, LOW);
		shiftOut(dataPin, clockPin, LSBFIRST, leds);
		digitalWrite(latchPin, HIGH);
	
	/*
	TIME LED
	*/
	delay(50);
}


int zmierzOdleglosc() {
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
 
  return dystans;
}