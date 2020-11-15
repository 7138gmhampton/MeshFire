#include <Arduino.h>
#include <HardwareSerial.h>

int message_count{0};

void setup()
{
    Serial.begin(115200);
    // int message_count{0};
}

void loop()
{
    Serial.print("This is message number ");
    ++message_count;
    Serial.println(message_count);
    
    delay(2000);
}