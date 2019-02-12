#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {

private:
	sf::RectangleShape bullet;
	bool active;

public:
	Bullet();
	~Bullet();
	void Move(int playerNum);
	void Draw(sf::RenderWindow & window);
	void SetPos(sf::Vector2f pos);
	void CheckBoundaries(int playerNum);
	bool IsActive();
	void SetActive(bool isActive);

	int GetTop() { return bullet.getPosition().y; }
	int GetBottom() { return bullet.getPosition().y + bullet.getSize().y; }
	int GetLeft() { return bullet.getPosition().x; }
	int GetRight() { return bullet.getPosition().x + bullet.getSize().x; }
};
#endif