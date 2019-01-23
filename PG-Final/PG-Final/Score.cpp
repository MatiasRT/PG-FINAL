#include "Score.h"

void Score::Update(float & timer, int & score1, int & score2, int & winner, States & state) {
	if (timer <= 0) {
		timer = 0.22f;
		score1 -= 500;
		score2 -= 500;
	}

	if (score1 < 0) {
		winner = 2;
		state = OVER;
	}

	if (score2 < 0) {
		winner = 1;
		state = OVER;
	}

	if (score1 == 0 && score2 == 0) {
		winner = 3;
		state = OVER;
	}
}