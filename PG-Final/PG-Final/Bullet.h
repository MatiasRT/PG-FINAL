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
	void Move(int speed);
	void Draw(sf::RenderWindow & window);
	void SetPos(sf::Vector2f pos);
};