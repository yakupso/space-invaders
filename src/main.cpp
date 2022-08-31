#include <ncurses.h>
#include <unistd.h>

#include "field.h"
#include "settings.h"

int main() {
	Field field;
	int is_quit = 0;

	initscr();
    nodelay(stdscr, true);
    noecho();

	while (!is_quit) {
		int pressed_key;
		usleep(50000);
		clear();
        refresh();
        field.clear_field();
		field.update_field();
		field.draw_field();
		pressed_key = getch();
		if (!(pressed_key == ERR)) {
			if (pressed_key == MOVE_LEFT || pressed_key == MOVE_LEFT + 32) {
				field.ship.move(0);
			}
			if (pressed_key == MOVE_RIGHT || pressed_key == MOVE_RIGHT + 32) {
				field.ship.move(1);
			}
			if (pressed_key == FIRE) {
				field.ship.fire();
			}
			if (pressed_key == QUIT || pressed_key == QUIT + 32) {
				is_quit = 1;
			}
		}
		for (int i = 0; i < Bullet::CURR_NUM_OF_BULLETS; i++) {
			field.ship.bullets[i + 1].move();
		}
	}
	endwin();

	return 0;
}