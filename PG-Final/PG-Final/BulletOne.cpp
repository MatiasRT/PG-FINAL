#include "BulletOne.h"

void BulletOne::Move() {
	bullet.move(constant::BULLET_SPEED_X, -constant::BULLET_SPEED_Y);
}

void BulletOne::CheckBoundaries() {
	if (bullet.getPosition().y < constant::BULLET_COL_DOWN_Y)
		active = false;
}