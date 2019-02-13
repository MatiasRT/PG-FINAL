#include "BulletOne.h"

void BulletOne::Move() {
	bullet.move(constant::BULLER_SPEED_X, -constant::BULLET_SPEED_Y);
}

void BulletOne::CheckBoundaries() {
	if (bullet.getPosition().y < -50)
		active = false;
}