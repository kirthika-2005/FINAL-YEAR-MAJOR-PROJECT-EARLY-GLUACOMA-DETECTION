#include "Arduino.h"
#include "Wire.h"
#include "SPI.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "Button.h"

// Pin Definitions
#define OLED128X64_PIN_RST 15
#define OLED128X64_PIN_DC
#define OLED128X64_PIN_CS
#define PUSHBUTTON_PIN_2
#define TCS34725_PIN_LED
#define TCS34725_PIN_INT 0

// Object initialization
#define SSD1306_LCDHEIGHT 64
Adafruit_SSD1306 oLed128x64(OLED128X64_PIN_DC, OLED128X64_PIN_RST, OLED128X64_PIN_CS);
Button pushButton(PUSHBUTTON_PIN_2);

// define vars for testing menu
const int timeout = 10000;    // define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work.
// It runs first every time your circuit is powered with electricity.
void setup()
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial); // wait for serial port to connect. Needed for native USB

    Serial.println("start");

    oLed128x64.begin(SSD1306_SWITCHCAPVCC);
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
    oLed128x64.clearDisplay();
    oLed128x64.display();

    pushButton.init();
    menuOption = menu();
}

void loop()
{
    if (menuOption == '1')
    {
        // Monochrome 1.3 inch 128x64 OLED graphic display - Test Code
        oLed128x64.setTextSize(1);
        oLed128x64.setTextColor(WHITE);
        oLed128x64.setCursor(0, 10);
        oLed128x64.clearDisplay();
        oLed128x64.println("Circuito.io Rocks!");
        oLed128x64.display();
        delay(1);

        oLed128x64.startscrollright(0x00, 0x0F);
        delay(2000);
        oLed128x64.stopscroll();
        delay(1000);

        oLed128x64.startscrollleft(0x00, 0x0F);
        delay(2000);
        oLed128x64.stopscroll();
    }
    else if (menuOption == '2')
    {
        bool pushButtonVal = pushButton.read();
        Serial.print(F("pushButtonVal: "));
        Serial.println(pushButtonVal);
    }
    else if (menuOption == '3')
    {
    }

    if (millis() - time0 > timeout)
    {
    }

    menuOption = menu();
}

char menu()
{
    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Monochrome 1.3 inch 128x64 OLED graphic display"));
    Serial.println(F("(2) Mini Pushbutton Switch"));
    Serial.println(F("(3) RGB Color Sensor with IR filter and White LED - TCS34725"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));

    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available())
    {
        char c = Serial.read();

        if (isAlphaNumeric(c))
        {
            if (c == '1')
            {
                Serial.println(F("Now Testing Monochrome 1.3 inch 128x64 OLED graphic display"));
            }
            else if (c == '2')
            {
                Serial.println(F("Now Testing Mini Pushbutton Switch"));
            }
            else if (c == '3')
            {
                Serial.println(F("Now Testing RGB Color Sensor with IR filter and White LED - TCS34725 - note that this component doesn't have a test code"));
            }
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }

            time0 = millis();
            return c;
        }
    }
}
