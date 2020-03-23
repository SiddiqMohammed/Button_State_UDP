#include <Ethernet2.h>
#include <EthernetUdp2.h>
const int buttonPin1 = 2;    // the number of the pushbutton pin
const int buttonPin2 = 3;    // the number of the pushbutton pin
const int buttonPin3 = 4;    // the number of the pushbutton pin

int buttonState1;             // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin

int buttonState2;             // the current reading from the input pin
int lastButtonState2 = LOW;   // the previous reading from the input pin

int buttonState3;             // the current reading from the input pin
int lastButtonState3 = LOW;   // the previous reading from the input pin


// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime2 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime3 = 0;  // the last time the output pin was toggled
String  ReplyBuffer = "";
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

char incomingData[45];
char *saveptr;
String  ReplyBuffer1 = "";
String  ReplyBuffer2 = "";
String  ReplyBuffer3 = "";

byte mac[] = { 0x2C, 0xF7, 0xF1, 0x08, 0x0C, 0x15 }; //physical mac address

IPAddress localip(192, 168, 1, 101);                      // IP Address
IPAddress remoteip(192, 168, 1, 100);               // Remote IP

const unsigned int remotPort = 4242;                // Remote Port
const unsigned int localPort = 4241;                // Local Port
EthernetUDP Udp;

void setup()
{
  //Serial.begin(115200);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  Ethernet.begin(mac, localip);
  Udp.begin(localPort);

}

void loop()
{
  buttonone();
  buttontwo();
  buttonthree();
}

void buttonone()
{
  int reading1 = digitalRead(buttonPin1);
  if (reading1 != lastButtonState1)
  {
    lastDebounceTime1 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay)
  {
    if (reading1 != buttonState1)
    {
      buttonState1 = reading1;
      if (buttonState1 == HIGH)
      {
        Serial.println("B1");
        Udp.beginPacket(remoteip, remotPort);
        ReplyBuffer1 = "B1";
        Udp.print(ReplyBuffer1);
        Udp.endPacket();
        ReplyBuffer1 = "";
        Udp.flush();
      }
    }
  }
  lastButtonState1 = reading1;
}

void buttontwo()
{
  int reading2 = digitalRead(buttonPin2);
  if (reading2 != lastButtonState2)
  {
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay)
  {
    if (reading2 != buttonState2)
    {
      buttonState2 = reading2;
      if (buttonState2 == HIGH)
      {
        {
          Serial.println("B2");
          Udp.beginPacket(remoteip, remotPort);
          ReplyBuffer2 = "B2";
          Udp.print(ReplyBuffer2);
          Udp.endPacket();
          ReplyBuffer2 = "";
          Udp.flush();
        }
      }
    }
  }
  lastButtonState2 = reading2;
}

void buttonthree()
{
  int reading3 = digitalRead(buttonPin3);
  if (reading3 != lastButtonState3)
  {
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime3) > debounceDelay)
  {
    if (reading3 != buttonState3)
    {
      buttonState3 = reading3;
      if (buttonState3 == HIGH)
      {
        {
          Serial.println("B3");
          Udp.beginPacket(remoteip, remotPort);
          ReplyBuffer3 = "B3";
          Udp.print(ReplyBuffer3);
          Udp.endPacket();
          ReplyBuffer3 = "";
          Udp.flush();
        }
      }
    }
  }
  lastButtonState3 = reading3;
}
