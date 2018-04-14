#define trigPin 8
#define echoPin 7

//Pin connected to ST_CP of 74HC595
int latchPin = 6;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

int speakerPin = 3;

byte leds = 0;
int currentLED = 0;

int buffor[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
String bufforSound[] = { "", "", "", "", "", "", "", "", "" };
String march[] = { "a", "cH", "f", "a", "cH", "f", "a", "a", "a" };


#define a 440
#define f 349
#define cH 523

void setup()
{

  /* add setup code here */
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT); //Pin, do którego pod³¹czymy trig jako wyjœcie
	pinMode(echoPin, INPUT); //a echo, jako wejœcie

	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	pinMode(speakerPin, OUTPUT);

	
	

}	
bool WasReset = true;

void loop()
{
	/*
	beep(speakerPin, a, 500);
	beep(speakerPin, a, 500);
	beep(speakerPin, a, 500);
	beep(speakerPin, f, 350);
	beep(speakerPin, cH, 150);

	beep(speakerPin, a, 500);
	beep(speakerPin, f, 350);
	beep(speakerPin, cH, 150);
	beep(speakerPin, a, 1000);
	*/

	int odleglosc = zmierzOdleglosc();
	//Serial.println(odleglosc);
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
	
	if (odleglosc < 40)
	{
		//Serial.println(odleglosc);

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
			
			
			if (odleglosc <= 10)
			{
				tone(speakerPin, cH);
				//Serial.println("cH");
			}
			else if ( odleglosc<=25)
			{
				tone(speakerPin, f);
				//Serial.println("f");
			}
			else 
			{
				tone(speakerPin, a);
				//Serial.println("a");
			}


			digitalWrite(latchPin, LOW);
			shiftOut(dataPin, clockPin, LSBFIRST, leds);
			digitalWrite(latchPin, HIGH);

			if (WasReset)
			{
				WasReset = false;
				for (int i = 8; i >= 1; i--)
				{
					buffor[i] = buffor[i - 1];
				}
				buffor[0] = odleglosc;


				for (int i = 0; i <= 8; i++)
				{
					///Serial.print(buffor[i]);
					//Serial.print(" ");
				}
				//Serial.println();
			}

			BufforToSoundBuffor(buffor, bufforSound);

			for (int i = 0; i <= 8; i++)
			{
				Serial.print(bufforSound[i]);
				Serial.print(" ");
			}
			Serial.println();

			ValidateMarch(bufforSound, march);
		
	}
else
{
	WasReset = true;
	noTone(speakerPin);
}

	


		//leds = (odleglosc / 9)+0;
		//Serial.println(leds);

		//bitSet(leds, currentLED);
		//bitSet(leds, currentLED + 1);
	

		
	/*
	TIME LED
	*/
	delay(50);
}

void BufforToSoundBuffor(int buffor[], String bufforOfSound[])
{
	for (int i = 0; i<=8; i++)
	{
		if (buffor[i]<10)
		{ 
			
			bufforOfSound[i]= "cH";
		}
		else if (buffor[i]<25)
		{
			
			bufforOfSound[i]="f";
		}
		else if(buffor[i]<40)
		{
			
			bufforOfSound[i] = "a";
		}
	}
}

void ValidateMarch(String bufforOfSound[], String march[])
{
	bool isValid = true;

	for (int i = 0; i <= 8; i++)
	{
		if (bufforOfSound[i] != march[i])
		{
			isValid = false;
		}
	}

	if (isValid == true)
	{
		Serial.println("Login");
	}
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
void beep(unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{
	//digitalWrite(ledPin, HIGH);
	//use led to visualize the notes being played

	int x;
	long delayAmount = (long)(1000000 / frequencyInHertz);
	long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
	for (x = 0;x<loopTime;x++)
	{
		digitalWrite(speakerPin, HIGH);
		delayMicroseconds(delayAmount);
		digitalWrite(speakerPin, LOW);
		delayMicroseconds(delayAmount);
	}

	//digitalWrite(ledPin, LOW);
	//set led back to low

	delay(20);
	//a little delay to make all notes sound separate
}