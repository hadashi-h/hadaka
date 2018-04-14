#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9
#define trigPin 7
#define echoPin 6
bool access = false;

RFID rfid(SS_PIN, RST_PIN);

int serNum[5];

int cards[][5] = {
    { 182,57,84,73,146 },
    { 101,220,213,229,137 }
};



//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 5;
////Pin connected to DS of 74HC595
int dataPin = 4;

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
    SPI.begin();
    rfid.init();
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
   // CheckRfid();

    int odleglosc = zmierzOdleglosc();
    Serial.println(odleglosc);
    int prawidlowaOdleglosc;

    leds = 0;

    if (odleglosc < 40)
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


        if (odleglosc <= 10)
        {
            tone(speakerPin, cH);
            //Serial.println("cH");
        }
        else if (odleglosc <= 25)
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
        }

        BufforToSoundBuffor(buffor, bufforSound);

        ValidateMarch(bufforSound, march);

    }
    else
    {
        WasReset = true;
        noTone(speakerPin);
    }
    delay(50);
}

void BufforToSoundBuffor(int buffor[], String bufforOfSound[])
{
    for (int i = 0; i <= 8; i++)
    {
        if (buffor[i] < 10)
        {

            bufforOfSound[i] = "cH";
        }
        else if (buffor[i] < 25)
        {

            bufforOfSound[i] = "f";
        }
        else if (buffor[i] < 40)
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



int zmierzOdleglosc()
{
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
    for (x = 0; x < loopTime; x++)
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

void CheckRfid()
{
    if (rfid.isCard())
    {
        if (rfid.readCardSerial())
        {
            for (int x = 0; x < sizeof(cards); x++)
            {
                for (int i = 0; i < sizeof(rfid.serNum); i++)
                {
                    if (rfid.serNum[i] != cards[x][i])
                    {
                        access = false;
                        break;
                    }
                    else
                    {
                        access = true;
                    }
                }
                if (access) break;
            }

        }

        if (access)
        {
            Serial.print("Hubert");
        }
        else
        {
            //Serial.println("Not allowed!");
        }
    }

    rfid.halt();
}