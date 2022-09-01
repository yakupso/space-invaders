#ifndef SRC_ALIEN_H_
#define SRC_ALIEN_H_

#define MAX_NUM_OF_ALIENS 45
#define SHIFT_ODD_ROW 17
#define SHIFT_EVEN_ROW 13
#define STEP_X 8
#define STEP_Y 3

class Alien {
public:
	int x;
	int y;
	static int CURR_NUM_OF_ALIENS;
	Alien();
	Alien(int x_, int y_);
	void move_x(int dir);
	void move_y();
	void remove();
};

#endif  // SRC_ALIEN_H_