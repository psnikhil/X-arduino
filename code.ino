

//----------------------------------------------------------------
  //     Program:     LCD_temperature

  //     By: Constructed   https://www.youtube.com/channel/UCD4TpqX_CJW0d4YoLLaaHYA
//----------------------------------------------------------------
#include <LiquidCrystal.h>

// Arduino pins used for LCD
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
    lcd.begin(16, 2);
}

void loop() {
    float temperature = 0.0;   // stores the calculated temperature
    int sample;                // counts through ADC samples
    float ten_samples = 0.0;   // stores sum of 10 samples
  
    
    for (sample = 0; sample < 10; sample++) {
        // convert A0 value to temperature
        temperature = ((float)analogRead(A0) * 5.0 / 1024.0) - 0.5; 
        temperature = temperature / 0.01;
        // sample every 0.1 seconds
        delay(100);
        // sum of all samples
        ten_samples = ten_samples + temperature;
    }
    // get the average value of 10 temperatures
    temperature = ten_samples / 10.0;
    // display the temperature on the LCD
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.setCursor (0,1);
    lcd.print (temperature);
    lcd.print((char)223);
    lcd.print(" F ");
    ten_samples = 0.0;
}
