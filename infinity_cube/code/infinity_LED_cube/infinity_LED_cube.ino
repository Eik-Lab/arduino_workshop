#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    72
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define AVERAGE_SAMPLES 30
#define sensorPin  A0

#define UPDATES_PER_SECOND 1000

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;





void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    Serial.begin(9600);
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
}

void FillLEDsFromPaletteColors( uint8_t colorIndex, uint8_t brightness)
{
    for( int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}



// This part of the code is the one that runs the program. It will run repeatedly. 
void loop()
{
    // You can insert new code or functions between here
    // RedColor();
    uint8_t brightness = LedWithSound();

    // and here
  
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors(startIndex, brightness);
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
}



// Here you can make your own functions 
void RedColor() {
  fill_solid( currentPalette, 16, CRGB::Red);
}



// Using the cube with a sound sensor 

uint8_t LedWithSound() {
  uint8_t sensor_value = analogRead(A0);
  uint8_t brightness = 0;
  Serial.println(sensor_value);

  return brightness;
}




// Using the cube with temperature sensor 

void LedWithTempearute() {
  // Insert code here 
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  //voltage = voltage /2;
  //float temperatureC = (voltage - 0.5) * 100 ;
  float temperatureC = (voltage) * 100 ;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  Serial.print(voltage); Serial.print(" volts  -  ");
  Serial.print(temperatureC); Serial.print(" degrees C  -  ");
  Serial.print(temperatureF); Serial.println(" degrees F");

}





/* Different color schemes: 

LavaColors_p;            // orange, red, black and yellow), 
CloudColors_p;           // blue and white
OceanColors_p;           // blue, cyan and white
ForestColors_p;          // greens and blues
RainbowColors_p;         // standard rainbow animation
RainbowStripeColors_p;   // single colour, black space, next colour and so forth
PartyColors_p;           // red, yellow, orange, purple and blue
HeatColors_p;            // red, orange, yellow and white
*/

/* Different colors
CRGB::Red
CRGB::Gray
CRGB::Blue
CRGB::Black
CRGB::White

*/






