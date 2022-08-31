#ifndef SRC_FIELD_H_
#define SRC_FIELD_H_

#include <ncurses.h>
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
	//TODO: Aliens
	Field();
	~Field();
	void update_field();
	void draw_field();
	void clear_field();
};

#endif  // SRC_FIELD_H_