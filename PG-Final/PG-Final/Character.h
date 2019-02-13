#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <queue>
#include "Bullet.h"
#include "CollisionManager.h"

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

	void Update(sf::Vector2f playerPos, float deltaTime, bool& shoot, int& score);
	virtual void Input(float deltaTime, bool& shoot) = 0;
	virtual void Shoot() = 0;
	void Draw(sf::RenderWindow & window);
	void Movement(float deltaTime);
	//void Shoot(std::vector<Bullet>& bulletVec, int offset);
	//void CheckCollision(/*Bullet bullet,*/ int &score);

	int GetX() { return player.getPosition().x; }
	int GetY() { return player.getPosition().y; }
	sf::Vector2f GetPos() { return player.getPosition(); }
};
#endif