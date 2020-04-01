//Program for Command mode
#include <SoftwareSerial.h>

SoftwareSerial BTserial(D4, D3); // RX, TX


const long baudRate = 38400 ;
char c=' ';
boolean NL = true;

void setup()
{
    pinMode(D8, OUTPUT);
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");

    BTserial.begin(baudRate);
    Serial.print("BTserial started at "); Serial.println(baudRate);
    Serial.println(" ");
              digitalWrite(D8, HIGH);
}

void loop()
{
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
        c = BTserial.read();
        Serial.write(c);
         if(c == 48){
          digitalWrite(D8, LOW);
          Serial.print("zero");
          }
          if(c == 49){
          digitalWrite(D8, HIGH);
          Serial.print("one");
          }
    }

    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();
        BTserial.write(c);

        // Echo the user input to the main window. The ">" character indicates the user entered text.
        if (NL) { Serial.print(">");  NL = false; }
        Serial.write(c);
        if (c==10) { NL = true; }
    }
}
