
#include "joystick.h"
class inputDevice {

 private:
	snake* snake;
	int fileno;
	string name;
	int playerNum;
	void initializeController();
	
 Public:
	inputDevice(int fileno, int playerNum);
	inputDevice(int playerNum);
	buttonPress poll();
	void setSnake(snake* snake);


}
