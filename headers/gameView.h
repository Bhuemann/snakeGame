#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "common.h"

class SnakeGameView {

 private:
	//canvas object we will be drawing to
	Canvas *canvas;

	//draws a single pixel to the canvas
	void drawPixel(int x, int y, color c);

	//clears a single pixel
	void clearPixel(int x, int y);

	//clears entire board
	void clearBoard();
	
 public:
	SnakeGameView();
	
	//initialize canvas and its attributes
	void initialize(int boardSize, numSnakes);
	
	//deInitialize canvas
	void deInitialize();

	//draws start screen graphics
	void drawStart();

	//draws the amount of players selection screen. Selection arg represents curser focus 
	void drawPlayerAmount(int selection)
	
	//draws the new head of the snake and clears the tail unless tail is set to null
	void drawSnake(point head, point tail);
	
	//draws play again graphics
	void drawPlayAgain();
	
	//draws the board completely from 2-dementianal vector; Recommend using only for initialization 
	void drawBoard(vector<vector<int>> board);
	
	//draw game over graphics
	void drawGameOver(string playerName, int score);
	
	//draws the players score on the board
	void drawScore(int playerNumber, int score);
  
	//draw food at a random location on board
	void drawFood(point p);

	//draws a count down onto the screen. Also will put the thread to sleep as it counts down.
	void drawCountDown(int sec);
}

#endif
