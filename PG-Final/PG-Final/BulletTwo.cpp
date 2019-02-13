#include "BulletTwo.h"

void BulletTwo::Move() {
	bullet.move(constant::BULLER_SPEED_X, constant::BULLET_SPEED_Y);
}

void BulletTwo::CheckBoundaries() {
	if (bullet.getPosition().y > 650)
		active = false;
}