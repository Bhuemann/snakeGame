
#define BUTTON_TYPE 1
#define DPAD_TYPE 2
#define BUTTON_DOWN_PRESS 1
#define BUTTON_UP_PRESS 0
#define DPAD_UP_PRESS 0
#define DPAD_X_AXIS 0
#define DPAD_Y_AXIS 1


#define BUTTON_A 0
#define BUTTON_B 1
#define BUTTON_X 2
#define BUTTON_Y 3
#define BUTTON_LB 4
#define BUTTON_RB 5
#define BUTTON_SELECT 6
#define BUTTON_START 7


inputDevice(int fileno, int playerNum){

	this->fileno = fileno;
	this->playerNum = playerNum;
	setJoystickFd(fileno);	
}
inputDevice(int playerNum){

	this->playerNum = playerNum;

	initializeController();
}

private initializeController(){

	fileno = open_joystick("js" + (playerNum-1));
	if (fileno < 0) {
		printf("Error: failed to open controller pipe.\n");
		exit(1);
	}
}


public buttonPress poll(){


	int fd, rc;

	struct js_event jse;

	//Controller unplugged
	if(errno == ENODEV){

		printf("Controller disconnected!\n");

		while((filno = open_joystick("js" + (playerNum-1)) < 0){
			usleep(1000);
		}
			
		errno = 0;
			
	}

	rc = read_joystick_event(&jse);
	usleep(1000);

	if(rc == 1){
		if(jse.type == BUTTON_TYPE && jse.value == BUTTON_DOWN_PRESS){

			switch(jse.number){
				
			case BUTTON_A:
				printf("player%d pressed the A button\n", playerNum);
				return buttonPress.BUTTON_A;
			case BUTTON_B:
				printf("player%d pressed the B button\n", playerNum);
				return buttonPress.BUTTON_B;
			case BUTTON_X:
				printf("player%d pressed the X button\n", playerNum);
				return buttonPress.BUTTON_X;
			case BUTTON_Y:
				printf("player%d pressed the Y button\n", playerNum);
				return buttonPress.BUTTON_Y;
			case BUTTON_LB:
				printf("player%d pressed the LB button\n", playerNum);
				return buttonPress.BUTTON_LB;
			case BUTTON_RB:
				printf("player%d pressed the RB button\n", playerNum);
				return buttonPress.BUTTON_RB;
			case BUTTON_SELECT:
				printf("player%d pressed the SELECT button\n", playerNum);
				return buttonPress.BUTTON_SELECT;
			case BUTTON_START:
				printf("player%d pressed the START button\n", playerNum);
				return buttonPress.BUTTON_START;
			}
			
		}
		else if(jse.type == DPAD_TYPE && jse.value != DPAD_UP_PRESS){

			if(jse.number == DPAD_Y_AXIS){

				if(jse.value == -32767){
					printf("You pressed the DPAD UP\n");
					return buttonPress.DPAD_UP;
				}
				else{
					printf("You pressed the DPAD DOWN\n");
					return buttonPress.DPAD_DOWN;
				}
				
			}
			else if(jse.number == DPAD_X_AXIS){

				if(jse.value == -32767){
					printf("player%d pressed the DPAD LEFT\n", playerNum);
					return buttonPress.DPAD_LEFT;
				}
				else{
					printf("player%d pressed the DPAD RIGHT\n", playerNum);
					return buttonPress.DPAD_RIGHT;
				}
				
			}
			
		}

	}
	
}

public void setSnake(snake* snake){
	this->snake = snake;
}
public snake* getSnake(){
	return this->snake;
}
