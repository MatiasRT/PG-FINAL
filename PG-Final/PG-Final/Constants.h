#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constant {
	/* PLAYER */
	const int PLAYER_WIDTH = 60;
	const int PLAYER_HEIGHT = 60;
	const int PLAYER1_SPAWN_X = 400;
	const int PLAYER1_SPAWN_Y = 560;
	const int PLAYER2_SPAWN_X = 400;
	const int PLAYER2_SPAWN_Y = 40;
	const int HIT_POINTS = 250;

	/* BULLET */
	const int BULLER_WIDTH = 5;
	const int BULLER_HEIGHT = 30;
	const int BULLER_SPEED_X = 0;
	const int BULLET_SPEED_Y = 10;
	const int SHOOT1_OFFSET = -60;
	const int SHOOT2_OFFSET = 30;

	/* FONTS */
	const int FONT_SIZE1 = 18;
	const int FONT_SIZE2 = 30;
	const int FONT_SIZE3 = 25;
	const int FONT_SIZE4 = 10;

	/* WINDOW */
	const int WINDOW_MIN_X = 0;
	const int WINDOW_MAX_X = 800;
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	/* MISC */
	const int FRAMERATE = 60;
	const int INIT_SCORE = 50000;
}
#endif