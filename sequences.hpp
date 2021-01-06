#include "ledconstants.hpp"

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

void trace_bridges_to_center(CRGB * leds, int thickness, int delayTime, CRGB color);

void color_trace_outwards_from_center(CRGB * leds, int delayTime, CRGB color);

void color_trace_bridges_to_center(CRGB * leds, int delayTime, CRGB color);

void fade_squares_up_down(CRGB * leds, int delayFade, int delayUpDown, CRGB color);

void trace_square_with_delays(CRGB * leds, int thickness, int delayTrace, int delaySides, CRGB colorOne, CRGB colorTwo);

void trace_out_from_center(CRGB * leds, int thickness, int delayTime, CRGB color);

void alternate_sides_and_tops_with_alternating_corner_colors(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);

void fade_all_lights_up_in_sets(CRGB * leds, int fadeDelayTime, CRGB colorOne, CRGB colorTwo);

void squares_top_bottom_dash_left_right(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);

void top_bottom_dash_left_right(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);

void squares_left_right_dash_up_down(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);

void left_right_dash_up_down(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);

void set_both_squares_to_color(CRGB * leds, CRGB color);

void blink_all_lights(CRGB * leds, CRGB color, int delayTime);

void blink_squares_lights(CRGB * leds, CRGB color, int delayTime);

void blink_all_lights_with_ending(CRGB * leds, CRGB color, int delayTime);

void alternate_squares_sides_and_tops(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo);

void switch_between_sets_of_lights(CRGB * leds, int delayTime, CRGB color);

void square_cycle_speed_up_rainbow(CRGB * leds, int startDelay, int decrement, int numTimesAtMaxSpeed, int endDelay);

void tripple_swap_downwards(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree);

void tripple_swap_upwards(CRGB * leds, int delayTime, CRGB colorOne, CRGB colorTwo, CRGB colorThree);
