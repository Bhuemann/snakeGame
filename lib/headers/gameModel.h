#include "common.h"
#include "snake.h"
#include <vector>

class gameModel {

 private:

	vector<snake> snakeList(2);
	vector<inputDevice> inputList(2);
	vector<vector<int>> board(64, vector<int>(64));
	point foodLocation;
	const int numPlayers;
	const int boardWidth;
	const int boardLength;


 public:
	gameModel();

};

