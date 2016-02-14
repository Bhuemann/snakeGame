
#include "gameModel.h"

public gameModel(){

	this->numPlayers = 1;
	this->boardWidth = 64;
	this->boardLength = 64;
	
}

public void addInputDevice(inputDevice device){

	inputList.add(device);

}

public vector<inputDevice*> getInputDevices(){

	return inputList;

}
public vector<snake*> getSnakes(){

	return snakeList;

}
public vector<vector<int>> getBoard(){

	return board;

}
public point getFoodLocation(){

	return foodLocation

}
public void generateNewFoodLocation(){

	//get random x value between 0<=x<=64
	//get random y value between 0<=y<=64

	//create new point with x and y being attributes

	//set food location to point
	
}
