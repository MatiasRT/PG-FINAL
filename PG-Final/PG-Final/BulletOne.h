#ifndef BULLETONE_H
#define BULLETONE_H
#include "Bullet.h"
#include "Constants.h"
class BulletOne : public Bullet {
public:
	BulletOne() {};
	~BulletOne() {};
	void Move();
	void CheckBoundaries();
};
#endif