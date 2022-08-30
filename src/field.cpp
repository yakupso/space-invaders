#include "field.h"

Field::Field() {
	ship = Ship(HEIGHT, WIDTH);
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
            	field[y][x] = ' ';
            }
        }
    }
}

void Field::draw_field() {
	system("clear");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", field[y][x]);
        }
        printf("\n");
    }
}