#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Character {

private:
	sf::RectangleShape player;
	float velocity;

public:
	Character();
	~Character();

	//sf::RectangleShape GetPlayer() { return player; };

	void Update(float deltaTime);
	void Draw(sf::RenderWindow & window);
};