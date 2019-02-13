#include "BulletTwo.h"

void BulletTwo::Move() {
	bullet.move(constant::BULLET_SPEED_X, constant::BULLET_SPEED_Y);
}

void BulletTwo::CheckBoundaries() {
	if (bullet.getPosition().y > constant::BULLET_COL_UP_Y)
		active = false;
}