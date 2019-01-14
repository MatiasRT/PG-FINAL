#include "HUD.h"
#include "Constants.h"

HUD::HUD() {
	if (!font1.loadFromFile("Assets/beef.ttf")) {
		std::cout << "Error: Font1 loadFromFile failed" << std::endl;
	}
}

HUD::~HUD() {
	delete scoreText1;
	delete scoreText2;
}

void HUD::Menu() {

}

void HUD::Game() {
	scoreText1 = new sf::Text("0", font1, constant::FONT_SIZE1);
	scoreText1->setOrigin(sf::Vector2f(scoreText1->getLocalBounds().width / 2, 0));
	scoreText1->setPosition(360, 320);
	scoreText1->setFillColor(sf::Color(245, 147, 51));

	scoreText2 = new sf::Text("0", font1, constant::FONT_SIZE1);
	scoreText2->setOrigin(sf::Vector2f(scoreText2->getLocalBounds().width / 2, 0));
	scoreText2->setPosition(360, 280);
	scoreText2->setFillColor(sf::Color(245, 245, 0));
}

void HUD::Over(std::string pWin, int finalScore) {
	winText = new sf::Text("The Winner Is", font1, constant::FONT_SIZE2);
	winText->setOrigin(std::round(winText->getLocalBounds().width / 2), 20);
	winText->setPosition((800 / 2), 80);
	winText->setFillColor(sf::Color(245, 147, 51));

	playerW = new sf::Text(pWin, font1, constant::FONT_SIZE3);
	playerW->setOrigin(std::round(playerW->getLocalBounds().width / 2), 20);
	playerW->setPosition((800 / 2), 250);
	playerW->setFillColor(sf::Color(245, 147, 51));

	score = new sf::Text(std::to_string(finalScore), font1, constant::FONT_SIZE3);
	score->setOrigin(std::round(score->getLocalBounds().width / 2), 20);
	score->setPosition((800 / 2), 300);
	score->setFillColor(sf::Color(245, 147, 51));

	menu = new sf::Text("Press ENTER to continue", font1, constant::FONT_SIZE4);
	menu->setOrigin(std::round(menu->getLocalBounds().width / 2), 20);
	menu->setPosition((800 / 2), 500);
	menu->setFillColor(sf::Color(245, 147, 51));

	restart = new sf::Text("Press R to restart", font1, constant::FONT_SIZE4);
	restart->setOrigin(std::round(restart->getLocalBounds().width / 2), 20);
	restart->setPosition((800 / 2), 550);
	restart->setFillColor(sf::Color(245, 147, 51));
}

void HUD::Update(int score1, int score2) {
	scoreText1->setString(std::to_string(score1));
	scoreText2->setString(std::to_string(score2));
}

void HUD::DrawGame(sf::RenderWindow & window) {
	window.draw(*scoreText1);
	window.draw(*scoreText2);
}

void HUD::DrawOver(sf::RenderWindow & window) {
	window.draw(*winText);
	window.draw(*playerW);
	window.draw(*score);
	window.draw(*menu);
	//window.draw(*restart);
}