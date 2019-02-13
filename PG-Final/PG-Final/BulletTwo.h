#ifndef BULLETTWO_H
#define BULLETTWO_H
#include "Bullet.h"
#include "Constants.h"
class BulletTwo : public Bullet {
public:
	BulletTwo() {}
	~BulletTwo() {}
	void Move();
	void CheckBoundaries();
};
#endif