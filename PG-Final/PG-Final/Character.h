#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <queue>
#include "Bullet.h"
#include "CollisionManager.h"
#include "Constants.h"

class Character {
protected:
	sf::RectangleShape player;
	std::vector<Bullet*> bullets;

	float velocity;
	float cooldown;

private:
	sf::SoundBuffer hitBuffer;
	sf::Sound hit;

public:
	Character();
	~Character();

	virtual void Input(float deltaTime) = 0;
	virtual void Shoot() = 0;
	void Update(sf::Vector2f playerPos, float deltaTime, int& score);
	void Draw(sf::RenderWindow & window);
	void Movement(float deltaTime);

	int GetX() { return player.getPosition().x; }
	int GetY() { return player.getPosition().y; }
	sf::Vector2f GetPos() { return player.getPosition(); }
};
#endif