#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {

private:
	sf::RectangleShape bullet;

public:
	Bullet(sf::Vector2f size);
	~Bullet();
	void Move(int playerNum);
	void Draw(sf::RenderWindow & window);
	void SetPos(sf::Vector2f pos);

	int GetTop() { return bullet.getPosition().y; }
	int GetBottom() { return bullet.getPosition().y + bullet.getSize().y; }
	int GetLeft() { return bullet.getPosition().x; }
	int GetRight() { return bullet.getPosition().x + bullet.getSize().x; }
};
#endif