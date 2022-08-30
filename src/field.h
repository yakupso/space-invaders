#ifndef SRC_FIELD_H_
#define SRC_FIELD_H_

#include <stdio.h>
#include <stdlib.h>

#include "ship.h"
#include "alien.h"
#include "bullet.h"

#define HEIGHT 25
#define WIDTH 80


class Field {
public:
	Ship ship;
	char field[HEIGHT][WIDTH];
	//Alien aliens[20];
	//Bullet bullets[10];

	Field();
	//~Field();
	void update_field();
	void draw_field();
};

#endif  // SRC_FIELD_H_