#include "field.h"

int Field::SCORE = 0;
int Field::LEVEL = 1;
int Field::FINISHED = 0;

Field::Field() {
	ship = Ship(HEIGHT, WIDTH);

	for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            field[y][x] = ' ';
        }
    }

    int x, y, i;
    x = 5;
    y = 2;
    int shift = SHIFT_ODD_ROW;
    for (i = 0; i < MAX_NUM_OF_ALIENS; i++) {
        aliens[i] = Alien(x, y);
        if (x < WIDTH - shift) {
            x += STEP_X;
        } else {
            y += STEP_Y;
            if (((y - 2) / 3) % 2) {
                x = 9;
                shift = SHIFT_EVEN_ROW;
            } else {
                x = 5;
                shift = SHIFT_ODD_ROW;
            }
        }
    }
    aliens_dir = 1;
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
                field[y - 1][x] = '*';
            	field[y][x - 1] = '*';
                field[y][x + 1] = '*';
            } else {
                for (int i = 0; i < Bullet::CURR_NUM_OF_BULLETS; i++) {
                    if (x == ship.bullets[i].x && y == ship.bullets[i].y) {
                        field[y][x] = '.';
                    }
                }
                for (int i = 0; i < Alien::CURR_NUM_OF_ALIENS; i++) {
                    if (x == aliens[i].x && y == aliens[i].y) {
                        field[y][x] = 'O';
                        field[y - 1][x] = 'O';
                        field[y + 1][x] = 'O';
                        field[y][x - 1] = 'O';
                        field[y][x + 1] = 'O';
                    }
                }
            }
        }
    }
}

void Field::draw_interface() {
    for (int x = 0; x < WIDTH + 1; x++) {
        printw("-");
    }
    printw("-\n");
    printw("|");
    printw("%s", MOVE_INSTRUCTION);
    printw("|");
    for (int x = 0; x < 22; x++) {
        printw(" ");
    }
    if (LEVEL - 1 != MAX_LEVEL) {
        printw("%s%i", CURRENT_LEVEL_MESSAGE, LEVEL); 
    } else {
        printw("%s%i", CURRENT_LEVEL_MESSAGE, LEVEL - 1);
    }
    for (int x = 0; x < 27; x++) {
        printw(" ");
    }
    printw("|\n");

    printw("|");
    printw("%s", FIRE_INSTRUCTION);
    printw("|");
    for (int x = 0; x < 22; x++) {
            printw(" ");
    }
    printw("%s%i", CURRENT_SCORE_MESSAGE, SCORE);
    int score = SCORE;
    int shift;
    for (shift = 0; score / 10; shift++) {
        score /= 10;
    }
    for (int x = 0; x < 27 - shift; x++) {
        printw(" ");
    }
    printw("|\n");

    printw("|");
    printw("%s", QUIT_INSTRUCTION);
    printw("|");
    if (!Field::FINISHED && Field::LEVEL - 1 != MAX_LEVEL) {
        for (int x = 0; x < WIDTH - 23; x++) {
            printw(" ");
        }
    } else {
        if (Field::FINISHED) {
            for (int x = 0; x < 20; x++) {
                printw(" ");
            }
            printw("%s", GAME_OVER_MESSAGE);
            for (int x = 0; x < 24; x++) {
                printw(" ");
            }
        } else if (LEVEL - 1 == MAX_LEVEL) {
            for (int x = 0; x < 14; x++) {
                printw(" ");
            }
            printw("%s", CONGRATULATIONS_MESSAGE);
            for (int x = 0; x < 16; x++) {
                printw(" ");
            }
        }
    }
        printw("|\n");
    for (int x = 0; x < WIDTH + 1; x++) {
        printw("-");
    }
}

void Field::draw_field() {
	system("clear");
    for (int x = 0; x < WIDTH + 1; x++) {
        printw("-");
    }
    printw("-\n");
    for (int y = 0; y < HEIGHT; y++) {
        printw("|");
        for (int x = 0; x < WIDTH; x++) {
            printw("%c", field[y][x]);
        }
        printw("|\n");
    }
    for (int x = 0; x < WIDTH + 1; x++) {
        printw("-");
    }
    printw("-\n");
    draw_interface();
}

void Field::destroy_bullet() {
    for (int i = 0; i < Bullet::CURR_NUM_OF_BULLETS; i++) {
        if (ship.bullets[i].y <= 0) {
            ship.bullets[i].remove();
            for (int j = i; j <= Bullet::CURR_NUM_OF_BULLETS; j++) {
                ship.bullets[j] = ship.bullets[j + 1];
            }
        }
    }
}

void Field::move_aliens() {
    int max_x = aliens[0].x;
    int min_x = aliens[0].x;
    int max_y = aliens[0].y;
    for (int i = 1; i < Alien::CURR_NUM_OF_ALIENS; i++) {
        if (aliens[i].x > max_x) {
            max_x = aliens[i].x;
        }
        if (aliens[i].x < min_x) {
            min_x = aliens[i].x;
        }
        if (aliens[i].y > max_y) {
            max_y = aliens[i].y;
        }
    }
    if (aliens_dir && (max_x == WIDTH - 2 || min_x == 1)) {
        aliens_dir = 0;
        if (max_y < HEIGHT - 3) {
            for (int i = 0; i < Alien::CURR_NUM_OF_ALIENS; i++) {
                aliens[i].move_y();
            }
        } else {
            FINISHED++;
        }
    } else if (aliens_dir >= 0 && max_x < WIDTH - 2) {
        aliens_dir = 1;
        for (int i = 0; i < Alien::CURR_NUM_OF_ALIENS; i++) {
            aliens[i].move_x(aliens_dir);
        }
    } else if (aliens_dir <= 0 && min_x > 1) {
        aliens_dir = -1;
        for (int i = 0; i < Alien::CURR_NUM_OF_ALIENS; i++) {
            aliens[i].move_x(aliens_dir);
        }
    }
}

void Field::destroy_aliens() {
    for (int i = 0; i < Alien::CURR_NUM_OF_ALIENS; i++) {
        for (int j = 0; j < Bullet::CURR_NUM_OF_BULLETS; j++)
        if ((aliens[i].x == ship.bullets[j].x && aliens[i].y + 1 == ship.bullets[j].y) ||
            (aliens[i].x - 1 == ship.bullets[j].x && aliens[i].y == ship.bullets[j].y) ||
            (aliens[i].x + 1 == ship.bullets[j].x && aliens[i].y == ship.bullets[j].y)) {
            aliens[i].remove();
            SCORE++;
            for (int k = i; k <= Alien::CURR_NUM_OF_ALIENS; k++) {
                aliens[k] = aliens[k + 1];
            }
            ship.bullets[j].remove();
            for (int k = j; k <= Bullet::CURR_NUM_OF_BULLETS; k++) {
                ship.bullets[k] = ship.bullets[k + 1];
            }
        }
    }
}












