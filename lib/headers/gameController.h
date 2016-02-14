
#include "common.h"
#include "gameView.h"
#include "gameModel.h"


class gameController{

 private:
	gameView* view;
	gameModel* model;
	
 public:
	gameController(gameView* view, gameModel* model);
	gameController(gameView* view, gameModel* model, int fileno);

	//updates
	void updateBoard(point p, color c);

	//launch game's main loop
	void begin();

	//clean up after game ends
	void cleanUp();

	//does all the necessary steps to get the game ready to begin()
	void initialize();
	
}


