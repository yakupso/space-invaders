#ifndef SRC_FIELD_H_
#define SRC_FIELD_H_

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

#include "ship.h"
#include "alien.h"
#include "bullet.h"

#define HEIGHT 25
#define WIDTH 80

#define MAX_LEVEL 4

#define MOVE_INSTRUCTION " 'X' or 'Z' for move  "
#define FIRE_INSTRUCTION " 'SPACE' for fire     "
#define QUIT_INSTRUCTION " 'Q' for quit         "
#define CURRENT_LEVEL_MESSAGE "LEVEL: "
#define CURRENT_SCORE_MESSAGE "SCORE: "
#define GAME_OVER_MESSAGE "* GAME OVER *"
#define CONGRATULATIONS_MESSAGE "* CONGRATULATIONS YOU WIN *"

class Field {
public:
	static int FINISHED;
	static int SCORE;
	static int LEVEL;
	Ship ship;
	Alien aliens[MAX_NUM_OF_ALIENS];
	int aliens_dir;
	char field[HEIGHT][WIDTH];
	Field();
	~Field();
	void update_field();
	void draw_interface();
	void draw_field();
	void clear_field();
	void destroy_bullet();
	void move_aliens();
	void destroy_aliens();
};

#endif  // SRC_FIELD_H_