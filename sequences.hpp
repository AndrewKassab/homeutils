#include "LightShow.hpp"

void sequence_one(CRGB* leds, int delayTime, int thickness, CRGB colorOne, CRGB colorTwo);
void square_side_cycle(CRGB* leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree, CRGB colorFour);
void square_color_trace(CRGB * leds, int thickness, int delayTime, CRGB color);
void up_down_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo);
void left_right_trace(CRGB * leds, int thickness, int delayTime, CRGB colorOne, CRGB colorTwo);
void sides_to_middle(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree);
void trace_squares_and_middle(CRGB * leds, int delayTime, int thickness, CRGB color);
void trace_squares_corners_and_middle(CRGB * leds, int delayTime, int thickness, CRGB color);
void top_to_bottom(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);
void trace_upwards(CRGB * leds, int thickness, int delayTime, CRGB color);
void trace_downwards(CRGB * leds, int thickness, int delayTime, CRGB color);
void trace_to_center(CRGB * leds, int thickness, int delayTime, CRGB color);
void corners_cycle_towards_center(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);
void color_trace_to_center(CRGB * leds, int delayTime, CRGB color);
void color_trace_outwards_from_center(CRGB * leds, int delayTime, CRGB color);
void color_trace_bridges_to_center(CRGB * leds, int delayTime, CRGB color);
void fade_squares_up_down(CRGB * leds, int delayFade, int delayUpDown, CRGB color);
void trace_square_with_delays(CRGB * leds, int thickness, int delayTrace, int delaySides, CRGB colorOne, CRGB colorTwo);
void trace_out_from_center(CRGB * leds, int thickness, int delayTime, CRGB color);