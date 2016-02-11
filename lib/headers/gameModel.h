#include "common.h"
#include "snake.h"

class SnakeGameModel {

 private:
  snakeGameView *view;

  int** board;
  Snake snakes[];
  const int numPlayers;
  controller snakeController;

  int* calcSnakePos(int numSnake);

 public:
  model(snakeGameView *view);
  virtual ~model();

  //checks to see if board[x][y] is available (no snakes && inside board)
  static bool isAvailable(int x, int y);

  const int** getBoard() const {
    return board;
  }

  const int getNumPlayers() const {
    return numPlayers;
  }

  const Snake* getSnakes() const {
    return snakes;
  }

};
