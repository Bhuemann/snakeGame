#include "gameController.h"
#include "gameView.h"
#include "gameModel.h"
#include <string>
#include <exception>

int main(int argc, const char * argv[]){


	int fileno;
	gameView* view = gameView();
	gameModel* model = gameModel();
	gameController* controller;
	
	//check if controller fileno is passed
	if(argc > 1){
		
		try{
			fileno = stoi(argv[1]);
		}
		catch(invalid_argument e){
			printf("Error: invalid arguments passed through command line\n");
			exit(1);
		}

		controller = gameController(view, model, fileno)
		
	}
	else{

		//if not, let controller handle setting up input device
		controller = gameController(view, model);
		
	}

	
	controller.intialize();
	
	controller.begin();

	
}
