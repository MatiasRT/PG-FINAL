#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

class Character {

private:

	sf::RectangleShape player;

	float velocity;
	float cooldown;

public:
	Character();
	~Character();

	//sf::RectangleShape GetPlayer() { return player; };

	void Update(float deltaTime, sf::RenderWindow & window);
	void Draw(sf::RenderWindow & window);
	void Shoot(float deltaTime, sf::RenderWindow & window);

	int GetX() { return player.getPosition().x; }
	int GetY() { return player.getPosition().y; }
};