#include <LiquidCrystal_I2C.h>

// Create LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Custom Characters -------------------------
uint8_t arrow[8] = {0x00, 0x04, 0x06, 0x1F, 0x06, 0x04, 0x00};
// -------------------------------------------

void setup()
{
    lcd.init();
    lcd.backlight();
    pinMode(JOYSTICK_SW_PIN, INPUT);

    lcd.createChar(0, arrow); // Create data for displaying arrow character
}

void loop()
{
    lcd.home();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(0);
    delay(3000);
}