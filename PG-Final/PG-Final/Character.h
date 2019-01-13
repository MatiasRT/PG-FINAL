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
	Character(int x, int y);
	~Character();

	//sf::RectangleShape GetPlayer() { return player; };

	void Update(float deltaTime, int playerNum);
	void Input(float deltaTime, int playerNum);
	void Movement(float deltaTime);
	void Draw(sf::RenderWindow & window);
	void Shoot(std::vector<Bullet>* bulletVec, int offset);

	int GetX() { return player.getPosition().x; }
	int GetY() { return player.getPosition().y; }
};