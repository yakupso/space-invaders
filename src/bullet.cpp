#include "bullet.h"

int Bullet::CURR_NUM_OF_BULLETS = 0;

Bullet::Bullet() {
	x = 0;
	y = 0;
	speed = 0;
}

Bullet::Bullet(int x_, int y_) {
	x = x_;
	y = y_;
	speed = 1;
	CURR_NUM_OF_BULLETS++;
}

//TODO: !
Bullet::~Bullet() {
	CURR_NUM_OF_BULLETS--;
}

void Bullet::move() {
	y -= speed;
}