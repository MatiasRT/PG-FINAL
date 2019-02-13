#include "Score.h"

void Score::Update(float & timer, int & score1, int & score2, int & winner, States & state) {
	if (timer <= 0) {
		timer = constant::SUBTRACT_TIMER;
		score1 -= constant::SUBTRACT_SCORE;
		score2 -= constant::SUBTRACT_SCORE;
	}

	if (score1 < 0) {
		winner = constant::PLAYER_BLUE;
		state = OVER;
	}

	if (score2 < 0) {
		winner = constant::PLAYER_RED;
		state = OVER;
	}

	if (score1 == 0 && score2 == 0) {
		winner = constant::PLAYER_DRAW;
		state = OVER;
	}
}