#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

class Character {

private:

	sf::RectangleShape player;
	sf::Texture* texture;

	float velocity;
	float cooldown;

public:
	Character(int x, int y, std::string path);
	~Character();

	void Update(float deltaTime, int playerNum, bool* shoot);
	void Input(float deltaTime, int playerNum, bool* shoot);
	void Movement(float deltaTime);
	void Draw(sf::RenderWindow & window);
	void Shoot(std::vector<Bullet>* bulletVec, int offset);
	void CheckCollision(Bullet bullet, int *score);

	int GetX() { return player.getPosition().x; }
	int GetY() { return player.getPosition().y; }
};
#endif