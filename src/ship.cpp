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

void Ship::move() {
	x += speed;
}