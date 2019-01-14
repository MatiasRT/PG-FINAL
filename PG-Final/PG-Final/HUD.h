#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include <iostream>

class HUD {
private:
	sf::Font font1;

	sf::Text* scoreText1;
	sf::Text* scoreText2;
	sf::Text* winText;
	sf::Text* playerW;
	sf::Text* score;
	sf::Text* menu;
	sf::Text* restart;

public:
	HUD();
	~HUD();

	void Menu();
	void Game();
	void Over(std::string pWin, int finalScore);

	void Update(int score1, int score2);
	void DrawGame(sf::RenderWindow & window);
	void DrawOver(sf::RenderWindow & window);
};
#endif