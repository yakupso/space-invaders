#ifndef SRC_BULLET_H_
#define SRC_BULLET_H_

class Bullet {
public:
	int x;
	int y;
	float speed;
	static int CURR_NUM_OF_BULLETS;
	Bullet();
	Bullet(int x, int y);
	~Bullet();
	void remove();
	void move();
};

#endif  // SRC_BULLET_H_