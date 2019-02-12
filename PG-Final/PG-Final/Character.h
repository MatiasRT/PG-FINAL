#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <queue>
#include "Bullet.h"

class Character {

private:

	sf::RectangleShape player;
	sf::Texture* texture;

	sf::SoundBuffer atkBufferRED;
	sf::SoundBuffer atkBufferBLUE;
	sf::SoundBuffer hitBuffer;

	sf::Sound atkRED;
	sf::Sound atkBLUE;
	sf::Sound hit;

	float velocity;
	float cooldown;
	float inputLag1;
	float inputLag2;

public:
	Character(int x, int y, std::string path);
	~Character();

	void Update(float deltaTime, int playerNum, bool& shoot);
	void Input(float deltaTime, int playerNum, bool& shoot);
	void Movement(float deltaTime);
	void Draw(sf::RenderWindow & window);
	//void Shoot(std::vector<Bullet>& bulletVec, int offset);
	void Shoot(std::queue<Bullet*>* bulletQ, std::vector<Bullet>& vec, int offset);
	void CheckCollision(Bullet bullet, int &score);

	int GetX() { return player.getPosition().x; }
	int GetY() { return player.getPosition().y; }
};
#endif