#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class HUD {
private:
	sf::Font font1;

	sf::Text* scoreText1;
	sf::Text* scoreText2;

public:
	HUD();
	~HUD();

	void Update(int score1, int score2);
	void Draw(sf::RenderWindow & window);
};