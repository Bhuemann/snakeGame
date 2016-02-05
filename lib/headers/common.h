#include <vector>

extern const enum color {RED, BLUE, YELLOW, PURPLE, ORANGE, INDIGO, GREEN, NO_COLOR};
extern const enum direction { NORTH, EAST, SOUTH, WEST };
extern const enum buttonPress {BUTTON_A, BUTTON_B, BUTTON_X, BUTTON_Y, BUTTON_LB, BUTTON_RB, BUTTON_START, BUTTON_SELECT, DPAD_RIGHT, DPAD_LEFT, DPAD_UP, DPAD_DOWN };

typedef struct
{
  int x;
  int y;
}point;
