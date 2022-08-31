#include "field.h"

Field::Field() {
	ship = Ship(HEIGHT, WIDTH);

	for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            field[y][x] = ' ';
        }
    }
}

Field::~Field() {}

void Field::clear_field() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            field[y][x] = ' ';
        }
    }
}

void Field::update_field() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == ship.x && y == ship.y) {
            	field[y][x] = '*';
            } else {
                for (int i = 0; i < Bullet::CURR_NUM_OF_BULLETS; i++) {
                    if (x == ship.bullets[i + 1].x && y == ship.bullets[i + 1].y) {
                        field[y][x] = '.';
                    }
                }
            }
        }
    }
}

void Field::draw_field() {
	system("clear");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printw("%c", field[y][x]);
        }
        printw("\n");
    }
}