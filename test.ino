#include <Wire.h>
#include "SparkFun_ENS160.h"

SparkFun_ENS160 myENS;

void setup()
{
    Wire.begin();
    Serial.begin(115200);

    if (!myENS.begin())
    {
        Serial.println("ENS160 did not begin. Check wiring!");
        while (1)
            ;
    }

    myENS.setOperatingMode(SFE_ENS160_STANDARD);
}

void loop()
{
    if (myENS.checkDataStatus())
    {
        Serial.print("Air Quality Index (AQI): ");
        Serial.println(myENS.getAQI());

        Serial.print("Total Volatile Organic Compounds (TVOC) [ppb]: ");
        Serial.println(myENS.getTVOC());

        Serial.print("Estimated CO2 (eCO2) [ppm]: ");
        Serial.println(myENS.getECO2());
    }
    else
    {
        Serial.println("Waiting for new data...");
    }

    delay(2000);
}
