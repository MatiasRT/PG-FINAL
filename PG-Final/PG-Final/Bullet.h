#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {
protected:
	sf::RectangleShape bullet;
	bool active;
public:
	Bullet();
	~Bullet();
	virtual void Move() = 0;
	virtual void CheckBoundaries() = 0;
	void Draw(sf::RenderWindow & window);
	void SetPos(sf::Vector2f pos);
	bool IsActive();
	void SetActive(bool isActive);
	void Update();

	int GetTop() { return bullet.getPosition().y; }
	int GetBottom() { return bullet.getPosition().y + bullet.getSize().y; }
	int GetLeft() { return bullet.getPosition().x; }
	int GetRight() { return bullet.getPosition().x + bullet.getSize().x; }
	sf::Vector2f GetPos() { return bullet.getPosition(); }
};
#endif