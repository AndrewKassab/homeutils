#include "LightShow.hpp"

void default_setup(CRGB leds[]){
  FastLED.addLeds<WS2812, 2, GRB>(leds, 262);
}

void light_all_corners(CRGB leds[], CRGB color){
  leds[left_top_left_corner] = color;
  leds[left_top_right_corner] = color;
  leds[left_bottom_left_corner] = color;
  leds[left_bottom_right_corner] = color;
  leds[middle_bottom_left_corner] = color;
  leds[middle_bottom_right_corner] = color;
  leds[middle_top_left_corner] = color;
  leds[middle_top_middle] = color;
  leds[middle_top_right_corner] = color;
  leds[right_bottom_right_corner] = color;
  leds[right_bottom_left_corner] = color;
  leds[right_top_right_corner] = color;
  leds[right_top_left_corner] = color;
}

void turn_off_all_corners(CRGB leds[]){ 
  leds[left_top_left_corner] = CRGB(0,0,0);
  leds[left_top_right_corner] = CRGB(0,0,0);
  leds[left_bottom_left_corner] = CRGB(0,0,0);
  leds[left_bottom_right_corner] = CRGB(0,0,0);
  leds[middle_bottom_left_corner] = CRGB(0,0,0);
  leds[middle_bottom_right_corner] = CRGB(0,0,0);
  leds[middle_top_left_corner] = CRGB(0,0,0);
  leds[middle_top_middle] = CRGB(0,0,0);
  leds[middle_top_right_corner] = CRGB(0,0,0);
  leds[right_bottom_right_corner] = CRGB(0,0,0);
  leds[right_bottom_left_corner] = CRGB(0,0,0);
  leds[right_top_right_corner] = CRGB(0,0,0);
  leds[right_top_left_corner] = CRGB(0,0,0);
}

void trace_outwards_evenly(CRGB leds[], int startIndex, int lengthOut, int thickness, int delayTime, CRGB color){ 
  for (int i = 0; i <= lengthOut-thickness; i++){
    for (int j = 0; j < thickness; j++){
      leds[startIndex+i+j] = color;
      leds[startIndex-i-j] = color;
    }
    FastLED.show();
    leds[startIndex+i] = CRGB(0,0,0);
    leds[startIndex-i] = CRGB(0,0,0);
    delay(delayTime);
  }
  for (int i = thickness; i >= 0; i--){
    leds[startIndex+lengthOut-i] = CRGB(0,0,0);
    leds[startIndex-lengthOut+i] = CRGB(0,0,0);
    FastLED.show();
    delay(delayTime);
  }
}

// factory 
LightSegment * get_left_square(CRGB* leds){
  return new LightSegment(leds, start, left_bottom_right_corner);
}
LightSegment * get_left_square_left(CRGB* leds){
  return new LightSegment(leds, left_top_left_corner, left_bottom_left_corner);
}
LightSegment * get_left_square_right(CRGB* leds){
  return new LightSegment(leds, start, left_top_right_corner-1);
}
LightSegment * get_left_square_top(CRGB* leds){
  return new LightSegment(leds, left_top_right_corner, left_top_left_corner-1);
}
LightSegment * get_left_square_bottom(CRGB* leds){
  return new LightSegment(leds, left_bottom_left_corner, left_bottom_right_corner);
}


LightSegment * get_right_square(CRGB* leds){
  return new LightSegment(leds, right_bottom_left_corner, end);
}
LightSegment * get_right_square_left(CRGB* leds){
  return new LightSegment(leds, right_top_left_corner, end);
}
LightSegment * get_right_square_right(CRGB* leds){
  return new LightSegment(leds, right_bottom_right_corner, right_top_right_corner-1); 
}
LightSegment * get_right_square_top(CRGB* leds){
  return new LightSegment(leds, right_top_right_corner, right_top_left_corner-1); 
}
LightSegment * get_right_square_bottom(CRGB* leds){
  return new LightSegment(leds, right_bottom_left_corner, right_bottom_right_corner-1); 
}


LightSegment * get_middle_arch(CRGB* leds){
  return new LightSegment(leds, middle_bottom_left_corner, middle_bottom_right_corner); 
}
LightSegment * get_middle_top(CRGB* leds){
  return new LightSegment(leds, middle_top_left_corner, middle_top_right_corner); 
}
LightSegment * get_middle_left(CRGB* leds){
  return new LightSegment(leds, middle_bottom_left_corner, middle_top_left_corner); 
}
LightSegment * get_middle_right(CRGB* leds){
  return new LightSegment(leds, middle_top_right_corner, middle_bottom_right_corner); 
}
LightSegment * get_middle_top_left(CRGB* leds){
  return new LightSegment(leds, middle_top_left_corner, middle_top_middle); 
}
LightSegment * get_middle_top_right(CRGB* leds){
  return new LightSegment(leds, middle_top_middle, middle_top_right_corner); 
}
  

LightSegment * get_left_bridge(CRGB* leds){
  return new LightSegment(leds, left_bottom_right_corner, middle_bottom_left_corner);
}
LightSegment * get_right_bridge(CRGB* leds){
  return new LightSegment(leds, middle_bottom_right_corner, right_bottom_left_corner);  
}
LightSegment * get_left_bridge_no_slant(CRGB* leds){
  return new LightSegment(leds, left_bottom_left_corner+1, middle_bottom_left_corner-5);
}
LightSegment * get_right_bridge_no_slant(CRGB* leds){
  return new LightSegment(leds, middle_bottom_right_corner+5, right_bottom_left_corner-1);
}


LightSegment * get_all_lights(CRGB* leds){
  return new LightSegment(leds, start, end); 
}

LightSegment * get_start_left_bridge_to_middle_top_left(CRGB* leds){
  return new LightSegment(leds, left_bottom_right_corner + 1, middle_top_left_corner);
}
LightSegment * get_middle_top_right_to_right_bridge_end(CRGB* leds){
  return new LightSegment(leds, middle_top_right_corner, right_bottom_left_corner-3);
}

LightSegment * get_left_square_left_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, left_top_left_corner + offset, left_bottom_left_corner - offset - 1);
}
LightSegment * get_left_square_top_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, left_top_right_corner + offset, left_top_left_corner - offset); 
}
LightSegment * get_left_square_right_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, 0 + offset, left_top_right_corner - offset - 1); 
}
LightSegment * get_left_square_bottom_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, left_bottom_left_corner+offset, left_bottom_right_corner-offset); 
}

LightSegment * get_right_square_left_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, right_top_left_corner + offset, end - offset);
}
LightSegment * get_right_square_top_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, right_top_right_corner + offset, right_top_left_corner - offset);
}
LightSegment * get_right_square_right_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, right_bottom_right_corner + offset, right_top_right_corner - offset-1);
}
LightSegment * get_right_square_bottom_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, right_bottom_left_corner + offset, right_bottom_right_corner - offset);
}

LightSegment * get_middle_left_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_bottom_left_corner + offset, middle_top_left_corner - offset);
}
LightSegment * get_middle_right_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_top_right_corner + offset, middle_bottom_right_corner - offset); 
}

LightSegment * get_middle_top_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_top_middle - offset, middle_top_middle + offset); 
}
LightSegment * get_middle_top_left_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_top_left_corner + offset, middle_top_middle - offset); 
}
LightSegment * get_middle_top_right_center_with_offset(CRGB* leds, int offset){
  return new LightSegment(leds, middle_top_middle + offset, middle_top_right_corner - offset); 
}

LightSegment * get_left_square_top_right_corner(CRGB * leds, int offset){
  return new LightSegment(leds, left_top_right_corner - offset, left_top_right_corner + offset);
}
LightSegment * get_left_square_top_left_corner(CRGB * leds, int offset){
  return new LightSegment(leds, left_top_left_corner - offset, left_top_left_corner + offset);
}
LightSegment * get_left_square_bottom_left_corner(CRGB * leds, int offset){
  return new LightSegment(leds, left_bottom_left_corner - offset, left_bottom_left_corner + offset);
}

LightSegment * get_right_square_top_right_corner(CRGB * leds, int offset){
  return new LightSegment(leds, right_top_right_corner - offset, right_top_right_corner + offset);
}
LightSegment * get_right_square_top_left_corner(CRGB * leds, int offset){
  return new LightSegment(leds, right_top_left_corner - offset, right_top_left_corner + offset); 
}

LightSegment * get_right_square_bottom_right_corner(CRGB * leds, int offset){
  return new LightSegment(leds, right_bottom_right_corner - offset, right_bottom_right_corner + offset);  
}

LightSegment * get_middle_bottom_left_corner(CRGB * leds, int offset){
  return new LightSegment(leds, middle_bottom_left_corner - 2, middle_bottom_left_corner + offset); 
}
LightSegment * get_middle_top_left_corner(CRGB * leds, int offset){
  return new LightSegment(leds, middle_top_left_corner - offset, middle_top_left_corner + offset); 
}
LightSegment * get_middle_top_right_corner(CRGB * leds, int offset){
  return new LightSegment(leds, middle_top_right_corner - offset, middle_top_right_corner + offset); 
}
LightSegment * get_middle_bottom_right_corner(CRGB * leds, int offset){
  return new LightSegment(leds, middle_bottom_right_corner - offset, middle_bottom_right_corner + 2); 
}
