#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <SFML/Graphics.hpp>

class CollisionManager {
	static CollisionManager* instance;
	CollisionManager() {};
public:
	~CollisionManager() {};
	bool CheckCollision(sf::Vector2f player, sf::Vector2f bullet);

	static CollisionManager* Instance() {
		if (instance == NULL) {
			instance = new CollisionManager();
		}
		return instance;
	};
};
#endif