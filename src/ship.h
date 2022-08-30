#ifndef SRC_SHIP_H_
#define SRC_SHIP_H_

class Ship {
public:
	int x;
	int y;
	float speed;
	Ship();
	Ship(int h, int w);
	void move();
};

#endif  // SRC_SHIP_H_