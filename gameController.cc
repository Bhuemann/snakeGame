

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

		



	}




}
