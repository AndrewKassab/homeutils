#include "sequences.hpp"

/* Square and center trace */
void sequence_one(CRGB* leds, int delayTime, int thickness, CRGB colorOne, CRGB colorTwo){

  for (int i = 0; i <= 79; i++){

      if ( i == 1 ){
        leds[76] = CRGB::Black;
        leds[185] = CRGB::Black;
      } else if ( i == 2 ){
        leds[77] = CRGB::Black;
        leds[184] = CRGB::Black;
      } else if ( i == 3 ) {
        leds[78] = CRGB::Black;
        leds[183] = CRGB::Black;
      } else if ( i == 4 ) {
        leds[79] = CRGB::Black;
        leds[182] = CRGB::Black;
      }

      delay(delayTime);

      // left square
      leds[start+i] = colorOne;
      leds[start+i-thickness] = CRGB::Black;

      // right square
      leds[end-i] = colorOne;
      leds[end-i+thickness] = CRGB::Black;

      // middle 
      if ( i != 42){
        leds[middle_bottom_left_corner+i-thickness] = CRGB::Black;
        leds[middle_bottom_right_corner-i+thickness] = CRGB::Black;
      }
      if ( i == 79 ){
        leds[middle_bottom_left_corner+2] = CRGB::Black;
        leds[middle_bottom_right_corner-2] = CRGB::Black;
      } else {
        leds[middle_bottom_left_corner+i] = colorTwo;
        leds[middle_bottom_right_corner-i] = colorTwo;
      }
      
      FastLED.show();
  } 
}

/* Square Cycle */
void square_side_cycle(CRGB* leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree, CRGB colorFour){
  LightSegment leftSquareLeftInSeq = get_left_square_left(leds);
  LightSegment leftSquareTopInSeq = get_left_square_top(leds);
  LightSegment leftSquareRightInSeq = get_left_square_right(leds);
  LightSegment leftSquareBottomInSeq = get_left_square_bottom(leds);
  LightSegment rightSquareTopInSeq = get_right_square_top(leds);
  LightSegment rightSquareRightInSeq = get_right_square_right(leds);
  LightSegment rightSquareLeftInSeq = get_right_square_left(leds);
  LightSegment rightSquareBottomInSeq = get_right_square_bottom(leds);

  FastLED.clear();
  leds[middle_top_left_corner] = CRGB::White;
  leds[middle_top_right_corner] = CRGB::White;
  leds[middle_bottom_left_corner] = CRGB::White;
  leds[middle_bottom_right_corner] = CRGB::White;
  leds[middle_top_middle] = CRGB::White;
  leftSquareLeftInSeq.setToColor(colorOne);
  rightSquareRightInSeq.setToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  leftSquareLeftInSeq.turnOff();
  rightSquareRightInSeq.turnOff();
  leftSquareTopInSeq.setToColor(colorTwo);
  rightSquareTopInSeq.setToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  leftSquareTopInSeq.turnOff();
  rightSquareTopInSeq.turnOff();
  leftSquareRightInSeq.setToColor(colorThree);
  rightSquareLeftInSeq.setToColor(colorThree);
  FastLED.show();
  delay(delayTime);
  leftSquareRightInSeq.turnOff();
  rightSquareLeftInSeq.turnOff();
  leftSquareBottomInSeq.setToColor(colorFour);
  rightSquareBottomInSeq.setToColor(colorFour);
  FastLED.show();

}

void square_color_trace(CRGB * leds, int thickness, int delayTime, CRGB color){
  LightSegment leftSquare = get_left_square(leds);
  LightSegment rightSquare = get_right_square(leds);
  SegmentList squares = SegmentList(&leftSquare);
  squares.add(&rightSquare);
  boolean reverseTable[2] = {true, false};
  squares.traceAllAndRemain(thickness,delayTime,reverseTable, color);
}

void up_down_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment leftSquareLeft = get_left_square_left(leds);
  LightSegment leftSquareRight = get_left_square_right(leds);
  LightSegment rightSquareLeft = get_right_square_left(leds);
  LightSegment rightSquareRight = get_right_square_right(leds);
  LightSegment middleLeft = get_middle_left(leds);
  LightSegment middleRight = get_middle_right(leds);
  SegmentList lights = SegmentList(&leftSquareLeft);
  lights.add(&leftSquareRight);
  lights.add(&rightSquareLeft);
  lights.add(&rightSquareRight);
  lights.add(&middleLeft);
  lights.add(&middleRight);
  boolean reverseTable[6] = {true, false, true, false, true, false};
  lights.traceAllKeepEnd(thickness, delayTime,reverseTable, colorOne);
  reverseTable[0] = false;
  reverseTable[2] = false;
  reverseTable[4] = false;
  reverseTable[1] = true;
  reverseTable[3] = true;
  reverseTable[5] = true;
  lights.traceAllKeepEnd(thickness, delayTime,reverseTable, colorTwo);
}

void left_right_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment leftSquareTop = get_left_square_top(leds);
  LightSegment leftSquareBottom = get_left_square_bottom(leds);
  LightSegment rightSquareTop = get_right_square_top(leds);
  LightSegment rightSquareBottom = get_right_square_bottom(leds);
  LightSegment middleTopLeft = get_middle_top_left(leds);
  LightSegment middleTopRight = get_middle_top_right(leds);
  SegmentList lights = SegmentList(&leftSquareTop);
  lights.add(&leftSquareBottom);
  lights.add(&rightSquareTop);
  lights.add(&rightSquareBottom);
  lights.add(&middleTopLeft);
  lights.add(&middleTopRight);
  boolean reverseTable[6] = {true, true, false, false, true, false};
  lights.traceAllKeepEnd(thickness, delayTime,reverseTable, colorOne);
  reverseTable[0] = false;
  reverseTable[2] = true;
  reverseTable[4] = false;
  reverseTable[1] = false;
  reverseTable[3] = true;
  reverseTable[5] = true;
  lights.traceAllKeepEnd(thickness, delayTime,reverseTable, colorTwo);
}

void sides_to_middle(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree){
  LightSegment allLights = get_all_lights(leds);
  allLights.turnOff();
  LightSegment leftSquareLeft = get_left_square_left(leds);
  LightSegment rightSquareRight = get_right_square_right(leds);
  SegmentList outer = SegmentList(&leftSquareLeft);
  outer.add(&rightSquareRight);
  LightSegment leftSquareRight = get_left_square_right(leds);
  LightSegment rightSquareLeft = get_right_square_left(leds);
  SegmentList middle = SegmentList(&leftSquareRight);
  middle.add(&rightSquareLeft);
  LightSegment middleLeft = get_middle_left(leds);
  LightSegment middleRight = get_middle_right(leds);
  SegmentList inner = SegmentList(&middleLeft);
  inner.add(&middleRight);

  outer.setAllToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  outer.turnAllOff();
  middle.setAllToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  middle.turnAllOff();
  inner.setAllToColor(colorThree);
  FastLED.show();

}

// TODO: Fix the unclean transition in the top middle
void trace_squares_and_middle(CRGB * leds, int delayTime, int thickness, CRGB color){
  LightSegment leftSquare = get_left_square(leds);
  LightSegment rightSquare = get_right_square(leds);
  LightSegment middleArch = get_middle_arch(leds); 
  LightSegment allLights = get_all_lights(leds);
  SegmentList lights = SegmentList(&leftSquare);
  lights.add(&rightSquare);
  lights.add(&middleArch);
  lights.add(&middleArch);

  boolean reverseTable[4] = {false, true, true, false};
  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);
  allLights.turnOff(); 
}

void trace_squares_corners_and_middle(CRGB * leds, int delayTime, int thickness, CRGB color){
  LightSegment leftSquare = get_left_square(leds);
  LightSegment rightSquare = get_right_square(leds);
  LightSegment middleArch = get_middle_arch(leds); 
  LightSegment allLights = get_all_lights(leds);
  SegmentList lights = SegmentList(&leftSquare);
  lights.add(&leftSquare);
  lights.add(&rightSquare);
  lights.add(&rightSquare);
  lights.add(&middleArch);
  lights.add(&middleArch);

  boolean reverseTable[6] = {false, true, false, true, true, false};
  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);
  allLights.turnOff(); 

}

void top_to_bottom(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment allLights = get_all_lights(leds);
  LightSegment leftSquareTop = get_left_square_top(leds);
  LightSegment leftSquareBottom = get_left_square_bottom(leds);
  LightSegment rightSquareTop = get_right_square_top(leds);
  LightSegment rightSquareBottom = get_right_square_bottom(leds);
  LightSegment middleTop = get_middle_top(leds);
  LightSegment leftBridge = get_left_bridge(leds);
  LightSegment rightBridge = get_right_bridge(leds);
  allLights.turnOff();

  SegmentList sideTopsAndBridges = SegmentList(&leftSquareTop);
  sideTopsAndBridges.add(&rightSquareTop);
  sideTopsAndBridges.add(&rightBridge);
  sideTopsAndBridges.add(&leftBridge);

  SegmentList middleTopAndSideBottoms = SegmentList(&leftSquareBottom);
  middleTopAndSideBottoms.add(&rightSquareBottom);
  middleTopAndSideBottoms.add(&middleTop);

  middleTopAndSideBottoms.setAllToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  middleTopAndSideBottoms.turnAllOff();
  sideTopsAndBridges.setAllToColor(colorTwo);
  FastLED.show();
}

void trace_upwards(CRGB * leds, int thickness, int delayTime, CRGB color){
  LightSegment leftSquareLeft = get_left_square_left(leds);
  LightSegment leftSquareRight = get_left_square_right(leds);
  LightSegment middleLeft = get_middle_left(leds);
  LightSegment middleRight = get_middle_right(leds);
  LightSegment rightSquareLeft = get_right_square_left(leds);
  LightSegment rightSquareRight = get_right_square_right(leds);

  SegmentList lights = SegmentList(&leftSquareLeft);
  lights.add(&leftSquareRight);
  lights.add(&middleLeft);
  lights.add(&middleRight);
  lights.add(&rightSquareLeft);
  lights.add(&rightSquareRight);

  boolean reverseTable[6] = {true, false, false, true, true, false};

  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);

}

void trace_downwards(CRGB * leds, int thickness, int delayTime, CRGB color){
  LightSegment leftSquareLeft = get_left_square_left(leds);
  LightSegment leftSquareRight = get_left_square_right(leds);
  LightSegment middleLeft = get_middle_left(leds);
  LightSegment middleRight = get_middle_right(leds);
  LightSegment rightSquareLeft = get_right_square_left(leds);
  LightSegment rightSquareRight = get_right_square_right(leds);

  SegmentList lights = SegmentList(&leftSquareLeft);
  lights.add(&leftSquareRight);
  lights.add(&middleLeft);
  lights.add(&middleRight);
  lights.add(&rightSquareLeft);
  lights.add(&rightSquareRight);

  boolean reverseTable[6] = {false, true, true, false, false, true};

  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);
}

void trace_to_center(CRGB * leds, int thickness, int delayTime, CRGB color){
  LightSegment startToMiddle = LightSegment(leds, start, middle_top_middle);
  LightSegment endToMiddle = LightSegment(leds, middle_top_middle, end);

  SegmentList lights = SegmentList(&startToMiddle);
  lights.add(&endToMiddle);
  boolean reverseTable[2] = {false, true};
  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color);
}

void trace_out_from_center(CRGB * leds, int thickness, int delayTime, CRGB color){
  LightSegment startToMiddle = LightSegment(leds, start, middle_top_middle);
  LightSegment endToMiddle = LightSegment(leds, middle_top_middle, end);

  SegmentList lights = SegmentList(&startToMiddle);
  lights.add(&endToMiddle);
  boolean reverseTable[2] = {true, false};
  lights.traceAllDontRemain(thickness, delayTime, reverseTable, color );
}

void corners_cycle_towards_center(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo){
  int offset = 6;

  LightSegment leftSquareTopRight = get_left_square_top_right_corner(leds, offset);
  LightSegment leftSquareTopLeft = get_left_square_top_left_corner(leds, offset);
  LightSegment leftSquareBottomLeft = get_left_square_bottom_left_corner(leds, offset);
  LightSegment leftSquareBottomRight = LightSegment(leds, left_bottom_right_corner - offset, left_bottom_right_corner);
  LightSegment leftSquareRightBottom = LightSegment(leds, start, start + offset - 1);
  LightSegment middleBottomLeftCorner = get_middle_bottom_left_corner(leds, offset);
  LightSegment middleTopLeftCorner = get_middle_top_left_corner(leds, offset);
  LightSegment middleTopRightCorner = get_middle_top_right_corner(leds, offset);
  LightSegment middleBottomRightCorner = get_middle_bottom_right_corner(leds, offset);
  LightSegment rightBottomLeft = LightSegment(leds, right_bottom_left_corner, right_bottom_left_corner + offset);
  LightSegment rightLeftBottom = LightSegment(leds, end - offset - 1, end);
  LightSegment rightBottomRightCorner = get_right_square_bottom_right_corner(leds, offset);
  LightSegment rightTopRightCorner  = get_right_square_top_right_corner(leds, offset);
  LightSegment rightTopLeftCorner  = get_right_square_top_left_corner(leds, offset);
  LightSegment middleTopMiddle = get_middle_top_center_with_offset(leds, offset);

  SegmentList first = SegmentList(&leftSquareTopRight);
  first.add(&rightTopLeftCorner);
  SegmentList second = SegmentList(&leftSquareTopLeft);
  second.add(&rightTopRightCorner);
  SegmentList third = SegmentList(&leftSquareBottomLeft);
  third.add(&rightBottomRightCorner);
  SegmentList fourth = SegmentList(&leftSquareBottomRight);
  fourth.add(&rightBottomLeft);
  fourth.add(&rightLeftBottom);
  fourth.add(&leftSquareRightBottom);
  SegmentList sixth = SegmentList(&middleBottomLeftCorner);
  sixth.add(&middleBottomRightCorner);
  SegmentList seventh = SegmentList(&middleTopLeftCorner);
  seventh.add(&middleTopRightCorner);

  first.setAllToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  second.setAllToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  third.setAllToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  fourth.setAllToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  sixth.setAllToColor(colorOne);
  FastLED.show();
  delay(delayTime);
  seventh.setAllToColor(colorTwo);
  FastLED.show();
  delay(delayTime);
  middleTopMiddle.setToColor(colorOne);
  FastLED.show();
}

void color_trace_to_center(CRGB * leds, int delayTime, CRGB color){
  LightSegment startToMiddle = LightSegment(leds, start, middle_top_middle);
  LightSegment endToMiddle = LightSegment(leds, middle_top_middle, end);

  SegmentList lights = SegmentList(&startToMiddle);
  lights.add(&endToMiddle);
  boolean reverseTable[2] = {false, true};
  lights.traceAllAndRemain(1, delayTime, reverseTable, color );

}

void color_trace_outwards_from_center(CRGB * leds, int delayTime, CRGB color){
  LightSegment startToMiddle = LightSegment(leds, start, middle_top_middle);
  LightSegment endToMiddle = LightSegment(leds, middle_top_middle, end);

  SegmentList lights = SegmentList(&startToMiddle);
  lights.add(&endToMiddle);
  boolean reverseTable[2] = {true, false};
  lights.traceAllAndRemain(1, delayTime, reverseTable, color );
}

void color_trace_bridges_to_center(CRGB * leds, int delayTime, CRGB color){
  LightSegment leftToMiddle = LightSegment(leds, left_bottom_right_corner, middle_top_middle);
  LightSegment rightToMiddle = LightSegment(leds, middle_top_middle, right_bottom_left_corner);

  SegmentList lights = SegmentList(&leftToMiddle);
  lights.add(&rightToMiddle);
  boolean reverseTable[2] = {false, true};
  lights.traceAllAndRemain(1, delayTime, reverseTable, color );
}

void fade_squares_up_down(CRGB * leds, int delayFade, int delayUpDown, CRGB color){
  LightSegment leftSquare = get_left_square(leds);
  LightSegment rightSquare = get_right_square(leds);

  SegmentList squares = SegmentList(&leftSquare);
  squares.add(&rightSquare);

  squares.fadeAllIn(delayFade, color);
  delay(delayUpDown);
  squares.fadeAllDown(delayFade + 28);
}

void trace_square_with_delays(CRGB * leds, int thickness, int delayTrace, int delaySides, CRGB colorOne, CRGB colorTwo){

  LightSegment leftSquareTop = get_left_square_top(leds);
  LightSegment rightSquareTop = get_right_square_top(leds);

  SegmentList one = SegmentList(&leftSquareTop);
  one.add(&rightSquareTop);

  LightSegment leftSquareLeft = get_left_square_left(leds);
  LightSegment rightSquareRight = get_right_square_right(leds);
  SegmentList two = SegmentList(&leftSquareLeft);
  two.add(&rightSquareRight);

  LightSegment leftSquareBottom = get_left_square_bottom(leds);
  LightSegment rightSquareBottom = get_right_square_bottom(leds);
  SegmentList three = SegmentList(&leftSquareBottom);
  three.add(&rightSquareBottom);

  LightSegment leftSquareRight = get_left_square_right(leds);
  LightSegment rightSquareLeft = get_right_square_left(leds);
  SegmentList four = SegmentList(&leftSquareRight);
  four.add(&rightSquareLeft);

  boolean reverseTable[2] = {false, true};

  one.traceAllKeepEnd(thickness, delayTrace, reverseTable, colorOne);
  delay(delaySides);
  FastLED.clear();
  two.traceAllKeepEnd(thickness, delayTrace, reverseTable, colorTwo);
  delay(delaySides);
  FastLED.clear();
  three.traceAllKeepEnd(thickness, delayTrace, reverseTable, colorOne);
  delay(delaySides);
  FastLED.clear();
  four.traceAllKeepEnd(thickness, delayTrace, reverseTable, colorTwo);
}


void alternate_sides_and_tops_with_alternating_corner_colors(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo){
  SegmentList squareLeftRight = SegmentList(&get_left_square_left(leds));
  squareLeftRight.add(&get_left_square_right(leds));
  squareLeftRight.add(&get_right_square_right(leds));
  squareLeftRight.add(&get_right_square_left(leds));
  SegmentList middleSides = SegmentList(&get_middle_left(leds));
  middleSides.add(&get_middle_right(leds));
  SegmentList squareTopBottom = SegmentList(&get_left_square_top(leds));
  squareTopBottom.add(&get_left_square_bottom(leds));
  squareTopBottom.add(&get_right_square_top(leds));
  squareTopBottom.add(&get_right_square_bottom(leds));
  squareLeftRight.setAllToColor(colorOne);
  // TODO:
  //light_all_corners(leds, colorTwo);
  FastLED.show();
  delay(delayTime);
  squareLeftRight.turnAllOff();
  get_middle_top(leds).setToColor(colorTwo);
  //TODO:
  //light_all_corners(leds, colorOne);
  FastLED.show();
  delay(delayTime);
  get_middle_top(leds).turnOff();
  squareTopBottom.setAllToColor(colorTwo);
  //TODO:
  //light_all_corners(leds, colorOne);
  FastLED.show();
  delay(delayTime);
  squareTopBottom.turnAllOff();
  middleSides.setAllToColor(colorOne);
  // TODO: 
  //light_all_corners(leds, colorTwo);
  FastLED.show();
}

void fade_all_lights_up_in_sets(CRGB * leds, int fadeDelayTime, CRGB colorOne, CRGB colorTwo){
  LightSegment leftSquareLeft = get_left_square_left(leds);
  LightSegment leftSquareRight = get_left_square_right(leds);
  LightSegment rightSquareLeft = get_right_square_left(leds);
  LightSegment rightSquareRight = get_right_square_right(leds);
  SegmentList setOne = SegmentList(&leftSquareLeft);
  setOne.add(&leftSquareRight);
  setOne.add(&rightSquareRight);
  setOne.add(&rightSquareLeft);

  LightSegment leftSquareTop = get_left_square_top(leds);
  LightSegment leftSquareBottom = get_left_square_bottom(leds);
  LightSegment rightSquareTop = get_right_square_top(leds);
  LightSegment rightSquareBottom = get_right_square_bottom(leds);
  SegmentList setTwo = SegmentList(&leftSquareTop);
  setTwo.add(&leftSquareBottom);
  setTwo.add(&rightSquareBottom);
  setTwo.add(&rightSquareTop);

  LightSegment middleLeft = get_middle_left(leds);
  LightSegment middleRight = get_middle_right(leds);
  SegmentList setThree = SegmentList(&middleLeft);
  setThree.add(&middleRight);

  LightSegment middleTop = get_middle_top(leds);
  LightSegment rightBridge = get_right_bridge(leds);
  LightSegment leftBridge = get_left_bridge(leds);
  SegmentList setFour = SegmentList(&middleTop);
  setFour.add(&leftBridge);
  setFour.add(&rightBridge);

  setOne.fadeAllIn(fadeDelayTime, colorOne);
  setTwo.fadeAllIn(fadeDelayTime, colorTwo);
  setThree.fadeAllIn(fadeDelayTime, colorOne);
  setFour.fadeAllIn(fadeDelayTime, colorTwo);
}