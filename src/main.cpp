#include <Arduino.h>
#include <IEC_SBus.h>

// SBUS SBus(&Serial1);
SBUS SBus(&Serial3);

void setup()
{
    Serial.begin(115200);
    SBus.Begin();
}

void loop()
{
    uint16_t RC_Channel[16];

    int isUpdated = SBus.Read(RC_Channel);
    if (isUpdated == 1)
    {
        for (int i = 0; i < 16; i++)
        {
            Serial.print(String() + RC_Channel[i] + " ");
        }
        Serial.println();
    }

    delay(1);
}