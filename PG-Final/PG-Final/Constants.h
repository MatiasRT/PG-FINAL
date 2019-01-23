#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

namespace constant {
	/* PLAYER */
	const int PLAYER_RED = 1;
	const int PLAYER_BLUE = 2;
	const int PLAYER_WIDTH = 60;
	const int PLAYER_HEIGHT = 60;
	const int PLAYER1_SPAWN_X = 400;
	const int PLAYER1_SPAWN_Y = 560;
	const int PLAYER2_SPAWN_X = 400;
	const int PLAYER2_SPAWN_Y = 40;
	const int HIT_POINTS = 250;
	const float VELOCITY_MULTIPLIER = 3000.0f;
	const float MAX_VELOCITY = 500.0f;
	const float VELOCITY_FRICTION = 1000.0f;

	/* BULLET */
	const int BULLER_WIDTH = 5;
	const int BULLER_HEIGHT = 30;
	const int BULLER_SPEED_X = 0;
	const int BULLET_SPEED_Y = 10;
	const int SHOOT1_OFFSET = -60;
	const int SHOOT2_OFFSET = 30;
	const float COOLDOWN = 0.30f;

	/* FONTS */
	const int FONT_SIZE1 = 18;
	const int FONT_SIZE2 = 30;
	const int FONT_SIZE3 = 25;
	const int FONT_SIZE4 = 10;
	const int FONT_SIZE5 = 28;
	const int MENU_TEXT_X = 400;
	const int MENU_TEXT_Y = 400;

	/* WINDOW */
	const int WINDOW_MIN_X = 0;
	const int WINDOW_MAX_X = 800;
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	/* MISC */
	const int FRAMERATE = 60;
	const int INIT_SCORE = 50000;
	const int MAX_SCORE = 100000;

	/* AUDIO */
	const int ATK_VOLUME = 40;
	const int HIT_VOLUME = 40;
	const int MUSIC_VOLUME = 80;

	/* SPRITES */
	const int ARROWLEFT_POSITION_X = 610;
	const int ARROWLEFT_POSITION_Y = 375;
	const int ARROWRIGHT_POSITION_X = 190;
	const int ARROWRIGHT_POSITION_Y = 375;

	/* ROUTES */
	const std::string MAIN_MUSIC = "Assets/Music/Play.wav";
	const std::string SHOOT_RED = "Assets/Music/Shoot_RED.wav";
	const std::string SHOOT_BLUE = "Assets/Music/Shoot_BLUE.wav";
	const std::string HIT_RED = "Assets/Music/Hit_RED.wav";
	const std::string HIT_BLUE = "Assets/Music/Hit_BLUE.wav";
	const std::string FONT = "Assets/beef.ttf";
	const std::string TEXTURE_ARROW = "Assets/Arrow.png";
	const std::string BACKGROUND = "Assets/BKG.png";
	const std::string P_RED = "Assets/RED.png";
	const std::string P_BLUE = "Assets/BLUE.png";
	const std::string TEXTURE_HOWTO = "Assets/HOW_TO.png";

	/* STRINGS */
	const std::string GAME_NAME = "RED VS BLUE";
	const std::string PLAY = "PLAY";
	const std::string HOW_TO = "HOWTO";
	const std::string EXIT = "EXIT";
	const std::string PLAYER1 = "PLAYER 1";
	const std::string PLAYER2 = "PLAYER 2";
	const std::string TIE = "NOBODY!... WAIT, REALLY?";

}
#endif