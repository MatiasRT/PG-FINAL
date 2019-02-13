#pragma once
#include "Bullet.h"
#include "Constants.h"
class BulletTwo : public Bullet {
public:
	BulletTwo();
	~BulletTwo();
	void Move();
	void CheckBoundaries();
};