
#include "common.h"
#include "gameView.h"
#include "gameModel.h"


class gameController{

 private:
	gameView view;
	gameModel model;
	
 public:
	gameController(gameView view, gameModel model);

	//updates
	void updateBoard(point p, color c);

	//launch game's main loop
	void begin();

	//clean up after game ends
	void cleanUp();


}


