// Uses 4x4 keypad and I2C LCD to enter password and power an output
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Length of password +1 for null character
#define PASSWORD_LENGTH 8

// Character to hold password input
char Data[PASSWORD_LENGTH];

// Password
char Master[PASSWORD_LENGTH] = "1234567";

// Pin connected to lock relay input
int lockOutput = 13;

// Counter for character entries
byte dataCount = 0;

// Character to hold key input
char customKey;

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

    // Set lockOutput as an OUTPUT pin
    pinMode(lockOutput, OUTPUT);
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("Enter Password:");

    customKey = customKeypad.getKey();

    if (customKey)
    {
        Data[dataCount] = customKey; // Enter keypress into the array
        lcd.setCursor(dataCount, 1); // Move the cursor to next position
        lcd.print(Data[dataCount]);  // Print the new character
        dataCount++;                 // Increment dataCount so that next loop will print in correct LCD position
    }

    // See if we have reached the password length
    if (dataCount == PASSWORD_LENGTH - 1)
    {
        lcd.clear();

        if (!strcmp(Data, Master))
        {
            lcd.print("Correct");
            digitalWrite(lockOutput, HIGH);
            delay(5000);
            digitalWrite(lockOutput, LOW);
        }
        else
        {
            // Password incorrect
            lcd.print("Incorrect");
            delay(1000);
        }

        lcd.clear();
        clearData();
    }
}

void clearData()
{
    // Go through array and clear all data
    while (dataCount != 0)
    {
        Data[dataCount--] = 0;
    }
    return;
}