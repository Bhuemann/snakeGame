#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "common.h"
#include "snake.h"
#include <vector>

class gameModel {

 private:

	vector<snake*> snakeList(2);
	vector<inputDevice*> inputList(2);
	vector<vector<int>> board(64, vector<int>(64));
	point foodLocation;
	const int numPlayers;
	const int boardWidth;
	const int boardLength;


 public:
	gameModel();

	//add a input object to vector array
	void addInputDevice(inputDevice device);

	//return inputList
	vector<inputDevice*> getInputDevices();

	//return snakeList
	vector<snake*> getSnakes();

	//return board
	vector<vector<int>> getBoard();

	//returns the point at which the food is located
	point getFoodLocation();

	//generates a random point and stores it into foodLocation
	void generateNewFoodLocation()
};

#endif
