#include "CollisionManager.h"

CollisionManager* CollisionManager::instance = NULL;

CollisionManager::CollisionManager() {

}

CollisionManager::~CollisionManager() {

}

bool CollisionManager::CheckCollision(sf::Vector2f player, sf::Vector2f bullet) {
	if (bullet.y < player.y + constant::PLAYER_HEIGHT &&
		bullet.y + constant::BULLER_HEIGHT > player.y &&
		bullet.x < player.x + constant::PLAYER_WIDTH - constant::PLAYER_HEIGHT / 2 &&
		bullet.x + constant::BULLER_WIDTH + constant::PLAYER_WIDTH / 2 > player.x) {
		//if (!isHit) {
			//isHit = true;
		//hit.play();
		//isHit = false;
	//}
		/*if (score < constant::MAX_SCORE)
			score += constant::HIT_POINTS;*/
		return true;
	}
	else
		return false;
}