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

    int slow = 16;
    int step = 0;
	while (!is_quit) {
		if (Alien::CURR_NUM_OF_ALIENS == 0) {
			field = Field();
			if (Field::LEVEL <= MAX_LEVEL) {
				Field::LEVEL++;
			}
			if (slow > 5) {
				slow -= 5;
			}
		}
		int pressed_key;
		usleep(30000);
		clear();
        refresh();
        if (!Field::FINISHED && Field::LEVEL - 1 != MAX_LEVEL) {
	        field.clear_field();
			field.update_field();
			field.destroy_bullet();
			field.destroy_aliens();
			if (!(step % slow)) {
				field.move_aliens();
			}
		}
		field.draw_field();
		pressed_key = getch();
		if (pressed_key != ERR) {
			if (pressed_key == MOVE_LEFT || pressed_key == MOVE_LEFT + 32) {
				if (field.ship.x > 1) {
					field.ship.move(0);
				}
			}
			if (pressed_key == MOVE_RIGHT || pressed_key == MOVE_RIGHT + 32) {
				if (field.ship.x < WIDTH - 2) {
					field.ship.move(1);
				}
			}
			if (pressed_key == FIRE) {
				if (Bullet::CURR_NUM_OF_BULLETS < MAX_NUM_OF_BULLETS) {
					field.ship.fire();
				}
			}
			if (pressed_key == QUIT || pressed_key == QUIT + 32) {
				is_quit = 1;
			}
		}
		for (int i = 0; i < Bullet::CURR_NUM_OF_BULLETS; i++) {
			field.ship.bullets[i].move();
		}
		step++;
	}
	endwin();

	return 0;
}
