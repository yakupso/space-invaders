#include "ship.h"

Ship::Ship() {
	x = 0;
	y = 0;
	speed = 0;
}

Ship::Ship(int h, int w) {
	x = w / 2 - 1;
	y = h - 1;
	speed = 1;
}

Ship::~Ship() {}

void Ship::move(int dir) {
	if (dir) {
		x += speed;
	} else {
		x -= speed;
	}
}

void Ship::fire() {
	bullets[Bullet::CURR_NUM_OF_BULLETS - 1] = Bullet(x, y + 2);
}