#include "alien.h"

int Alien::CURR_NUM_OF_ALIENS = 0;

Alien::Alien() {
	x = 0;
	y = 0;
}

Alien::Alien(int x_, int y_) {
	x = x_;
	y = y_;
	CURR_NUM_OF_ALIENS++;
}

void Alien::move_x(int dir) {
	x += dir;
}

void Alien::move_y() {
	y++;
}

void Alien::remove() {
	CURR_NUM_OF_ALIENS--;
}