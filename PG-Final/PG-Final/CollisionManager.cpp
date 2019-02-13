#include "CollisionManager.h"

CollisionManager* CollisionManager::instance = NULL;

bool CollisionManager::CheckCollision(sf::Vector2f player, sf::Vector2f bullet) {

	sf::Vector2f diff = player - bullet;

	float diffX = abs(diff.x);
	float diffY = abs(diff.y);

	if (diffX <= (constant::PLAYER_WIDTH / 2 + constant::BULLET_WIDTH / 2) &&
		diffY <= (constant::PLAYER_HEIGHT / 2 + constant::BULLET_HEIGHT / 2))
		return true;
	else return false;
}