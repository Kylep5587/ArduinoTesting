#includ < LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

void setup()
{
    lcd.begin(16, 2); // set LCD dimensions
}

void loop()
{
    lcd.print("Hello World");
    delay(3000);

    lcd.setCursor(2, 1); // Set cursor to second column, first row
    lcd.print("LCD Test");
    delay(3000);

    lcd.clear(); // Clears the screen

    lcd.blink();
    delay(4000);

    lcd.setCursor(7, 1);
    delay(3000);
    lcd.noBlink(); // Removes blinking cursor

    lcd.cursor();
    delay(4000);
    lcd.noCursor();
    delay(2000);

    lcd.clear();
}