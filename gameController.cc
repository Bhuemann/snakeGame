

public gameController(gameView* view, gameModel* model){

	this->view = view;
	this->model = model;

	inputDevice player1 = inputDevice(1);
	model->addInputDevice(player1);
	
}

public gameController(gameView* view, gameModel* model, int fileno){

	this->view = view;
	this->model = model;

	inputDevice player1 = inputDevice(fileno, 1);
	model->addInputDevice(player1);
}

void initialize(){

	//draw starting screen and prompt to start the game
	view->drawStart();

	//wait until user presses start

	//prompt the user for amount of players

	//create new input devices for specified players

	//create new snakes for each input device and link them together

	//initialize model->board with snake location, player score, and food

	//draw on canvas the board

}

void startCountDown(int sec){

	view->drawCountDown(sec);
}

void begin(){

	boolean gameIsRunning = true;

	while(gameIsRunning){

		vector<inputDevice> devices = model->getInputDevices();
		buttonPress button;

		//poll all controllers and change each snakes direction
		for(int i = 0; i < devices.size(); i++){

			button = devices.get(i)->poll();

			switch(button){
			case buttonPress.DPAD_UP:
				devices.get(i)->setDirection(direction.NORTH);
				break;
			case buttonPress.DPAD_DOWN:
				devices.get(i)->setDirection(direction.SOUTH);
				break;
			case buttonPress.DPAD_LEFT:
				devices.get(i)->setDirection(direction.WEST);
				break;
			case buttonPress.DPAD_RIGHT:
				devices.get(i)->setDirection(direction.EAST);
				break;
			}
		}


		//loop through all snakes and move them. Check collison and food location
		//TODO: fix when multiple snakes collide in same tick
		

	}




}
