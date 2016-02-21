#includ "snake.h"

class snake {

 private:
	vector<point> cords = vector<point>(6);
	bool hasEaten;
	color bodyColor;
	color headColor;
	direction snakeDirection;
	int score;

 public:
	snake(point head, color bodyColor);
	bool move();
	point getHead();
	point getTail();
	void grow();

} 
