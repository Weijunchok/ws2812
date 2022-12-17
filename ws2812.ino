
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
 
#define PIN        D1 // On Trinket or Gemma, suggest changing this to 1
 
#define NUMPIXELS 8 // Popular NeoPixel ring size
 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
 
void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
 
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}
 
int get_rand(){
  return rand()%255;
}
 
void loop() {
  //pixels.clear(); // Set all pixel colors to 'off'
 
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(get_rand(), get_rand(), get_rand()));
 
    pixels.show();   // Send the updated pixel colors to the hardware.
 
    delay(DELAYVAL); // Pause before next pass through loop
  }
}
