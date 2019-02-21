#ifndef SCORE_H
#define SCORE_H
#include "States.h"

class Score {
public:
	Score() {};
	~Score() {};
	void Update(float & timer, int & score1, int & score2, int & winner, States & state);
};
#endif