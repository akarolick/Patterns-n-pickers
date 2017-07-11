#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 29  // 84 HATS // 57 UNICYCLE // 82 VEST // 102 SKIRTS // 20 YARMULKE/FASCINATOR // 41 HEADDRESS // 29 GLOVES

//PATTERN PICKER!!!!
int patterns[] = {2,3};

#define DATA_PIN 1

#define HALF_LEDS (NUM_LEDS/2)
#define QUART_LEDS (NUM_LEDS/4)

/*//TODO: COLOR PICKER
#Blues
  LightBlue,SkyBlue,MidnightBlue,Navy,DarkBlue,MediumBlue,Teal,CadetBlue,Blue,DarkCyan,CornflowerBlue,Aquamarine,Aqua,LightSkyBlue,
#Greens
  DarkGreen,DarkOliveGreen,DarkGreen,OliveDrab,Green,SeaGreen,MediumAquamarine,LimeGreen,YellowGreen,LightGreen,LawnGreen,MediumAquamarine,ForestGreen
#Yellows
  Yellow,Orange
#Reds
  Red,Pink,Maroon,DarkRed,Orange,DarkRed,
#White

#Black

COLOR GRADIENT MAP RGB
      0,  255,  0,  0, // Red
     32,  171, 85,  0, // Orange
     64,  171,171,  0, // Yellow
     96,    0,255,  0, // Green
    128,    0,171, 85, // Aqua
    160,    0,  0,255, // Blue
    192,   85,  0,171, // Purple
    224,  171,  0, 85, // Pink
    255,  255,  0,  0};// and back to Red
*/

CRGB leds[NUM_LEDS];

void setup() { 
	LEDS.addLeds<WS2812,DATA_PIN,GRB>(leds,NUM_LEDS);
	LEDS.setBrightness(60);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(235); } } 
void fastFadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(150); } }
int pat = 0;

void loop ()
  {

      int R = random (0, 255);
      int G = random (0, 255);
      int B = random (0, 255);
      //static uint8_t i = 0;
      //static uint8_t j = 0;

      int i = HALF_LEDS;
      int j = (HALF_LEDS - 1);
      int k = (HALF_LEDS + QUART_LEDS);
      int l = (QUART_LEDS);
      int count;
      
  switch (patterns[pat]) {

//CHASE UP THE LENGTH OF THE STRAND
  case (1) :
  count = 1;
  while ( count <= 2 ) {
    for( int i = NUM_LEDS; i >= 0; i-- ) {
      leds[i] = CRGB(R, G, B);
      FastLED.show(); 
      fadeall();
      delay(25);
    }
    R = random (0, 255);
    G = random (0, 255);
    B = random (0, 255);
    count++;
  }
  break;

//CHASE DOWN THE LENGTH OF THE STRAND
 count = 1;
  case (2) :
  while ( count <= 2 ) {
    for( int i = 0; i <= NUM_LEDS; i++ ) {
      leds[i] = CRGB(R, G, B);
      FastLED.show(); 
      fadeall();
      delay(25);
    R = random (0, 255);
    G = random (0, 255);
    B = random (0, 255);
    }
    count++;
  }
    break;

//CHASING STRIPS ACROSS THE STRAND
  
  count = 1;
  case (3) :
  while ( count <= 2 ) {
	  while( i < (HALF_LEDS + QUART_LEDS)  && k <= NUM_LEDS && j > (QUART_LEDS) && l >= 0 ) {
      leds[i] = CRGB(R, G, B);
      leds[j] = CRGB(R, G, B);
      leds[k] = CRGB(R, G, B);
      leds[l] = CRGB(R, G, B);
		  FastLED.show(); 
		  fadeall();
		  delay(45);
      ++i;
      --j;
      ++k;
      --l;
	  }

    i = (HALF_LEDS + QUART_LEDS - 1);
    j = (HALF_LEDS - QUART_LEDS + 1);
    k = (NUM_LEDS);
    l = (0);

    while( i >= HALF_LEDS && k >= (HALF_LEDS + QUART_LEDS) && j <= (HALF_LEDS - 1) && l <= QUART_LEDS ){
      leds[i] = CRGB(R, G, B);
      leds[j] = CRGB(R, G, B);
      leds[k] = CRGB(R, G, B);
      leds[l] = CRGB(R, G, B);
      FastLED.show(); 
      fadeall();
      delay(45);
      --i;
      ++j;
      --k;
      ++l;
  }
  
  i = HALF_LEDS;
  j = (HALF_LEDS - 1);
  k = (HALF_LEDS + QUART_LEDS);
  l = (QUART_LEDS);
  
    R = random (0, 255);
    G = random (0, 255);
    B = random (0, 255);
  count = (count + 1);
  }
    break;

// SLOW FADE BETWEEN COLORS OVER THE ENTIRE STRIP

  count = 1;
  case (4) :
  while (count < 1) {

    for( int colorStep = 0; colorStep < 256; colorStep++ ) {

      int r = colorStep ;  // Redness starts at zero and goes up to full
      int g = 0;  // No green needed to go from blue to red
      int b = 255-colorStep;  // Blue starts at full and goes down to zero

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
      FastLED.show();
      delay(40); 
  }

    for( int colorStep = 0; colorStep < 256; colorStep++ ) {

      int r = 255-colorStep ;  // Redness starts at zero and goes up to full
      int g = colorStep;  // No green needed to go from blue to red
      int b = 0;  // Blue starts at full and goes down to zero

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
      FastLED.show();
      delay(40); 
  }

    for( int colorStep = 0; colorStep < 256; colorStep++ ) {

      int r = 0 ;  // Redness starts at zero and goes up to full
      int g = 255-colorStep;  // No green needed to go from blue to red
      int b = colorStep;  // Blue starts at full and goes down to zero

      for(int x = 0; x < NUM_LEDS; x++){
          leds[x] = CRGB(r,g,b);
      }
      FastLED.show();
      delay(40); 
  }
  count = (count + 1);
  }
    break;

// FAST CHASE BETWEEN TWO HALVES OF YOUR LED STRIP

    i = HALF_LEDS;
    j = (HALF_LEDS - 1);
    count = 1;
    case (5) :
  while ( count <= 10 ) {
      while( i <= NUM_LEDS && j >= 0 ) {
        leds[i] = CRGB(R, G, B);
        leds[j] = CRGB(R, G, B);
        FastLED.show(); 
        fastFadeall();
        ++i;
        --j;
      }

    R = random (0, 255);
    G = random (0, 255);
    B = random (0, 255);
      i = NUM_LEDS;
      j = 0;
      while( i >= HALF_LEDS && j <= (HALF_LEDS - 1)){
        leds[i] = CRGB(R, G, B);
        leds[j] = CRGB(R, G, B);
        FastLED.show(); 
        fastFadeall();
        i--;
        j++;
    }    
    
    R = random (0, 255);
    G = random (0, 255);
    B = random (0, 255);
   count++;    
  }
  break;

//PRETTY SPARKLES!!!!!

    count = 1;
    case (6) :
   while ( count <= 10) {
      int num = 0;  
      while( num <= NUM_LEDS )  {
        i = random (0, NUM_LEDS);
        leds[i] = CRGB(R,G,B);
        FastLED.show();
        fadeall();
        num++;
    R = random (0, 255);
    G = random (0, 255);
    B = random (0, 255);

     delay(45);
      }

   count++;
   }
   break;
  }
  ++pat;

}

