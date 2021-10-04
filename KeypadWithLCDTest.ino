#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Constants for row and column sizes
const byte ROWS = 4;
const byte COLS = 4;

// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// Connections to Arduino
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Create LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    // Setup LCD with backlight and initialize
    lcd.backlight();
    lcd.init();
}

void loop()
{
    // Get key value if presses
    char customKey = customKeypad.getKey();

    if (customKey)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(customKey);
    }
}