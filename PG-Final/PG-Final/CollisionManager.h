#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
class CollisionManager {
	static CollisionManager* instance;
	CollisionManager() {}
public:
	~CollisionManager() {}
	bool CheckCollision(sf::Vector2f player, sf::Vector2f bullet);

	static CollisionManager* Instance() {
		if (instance == NULL) {
			instance = new CollisionManager();
		}
		return instance;
	};
};