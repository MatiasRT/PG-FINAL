#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {

private:
	sf::RectangleShape bullet;
	int speed;
	bool enabled;

public:
	Bullet(sf::Vector2f size);
	~Bullet();
	void Move(int speed, int playerNum);
	void Draw(sf::RenderWindow & window);
	void SetPos(sf::Vector2f pos);

	int GetTop() { return bullet.getPosition().y; }
	int GetBottom() { return bullet.getPosition().y + bullet.getSize().y; }
	int GetLeft() { return bullet.getPosition().x; }
	int GetRight() { return bullet.getPosition().x + bullet.getSize().x; }
};