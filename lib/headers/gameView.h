#include "common.h"

class SnakeGameView {

 private:
  Canvas *canvas;

 public:
  SnakeGameView(Canvas *canvas);

  //initialized game view
  void init();

  //sets pixel at x,y with color c
  void drawPixel(int x, int y, color c);

  //clear pixel at specified x, y
  void clearPixel(int x, int y);

}
