#ifndef SRC_SHIP_H_
#define SRC_SHIP_H_

#include "bullet.h"

#define MAX_NUM_OF_BULLETS 24

class Ship {
public:
	int x;
	int y;
	float speed;
	Bullet bullets[MAX_NUM_OF_BULLETS];

	Ship();
	Ship(int h, int w);
	~Ship();
	void move(int dir);
	void fire();
};

#endif  // SRC_SHIP_H_