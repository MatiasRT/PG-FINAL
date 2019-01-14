#include "HUD.h"

HUD::HUD() {
	if (!font1.loadFromFile("Assets/beef.ttf")) {
		std::cout << "Error: Font1 loadFromFile failed" << std::endl;
	}

	scoreText1 = new sf::Text("0", font1, 18);
	scoreText1->setOrigin(sf::Vector2f(scoreText1->getLocalBounds().width / 2, 0));
	scoreText1->setPosition(360, 320);
	scoreText1->setFillColor(sf::Color(245, 147, 51));

	scoreText2 = new sf::Text("0", font1, 18);
	scoreText2->setOrigin(sf::Vector2f(scoreText2->getLocalBounds().width / 2, 0));
	scoreText2->setPosition(360, 280);
	scoreText2->setFillColor(sf::Color(245, 245, 0));
}

HUD::~HUD() {
	delete scoreText1;
	delete scoreText2;
}

void HUD::Update(int score1, int score2) {
	scoreText1->setString(std::to_string(score1));
	scoreText2->setString(std::to_string(score2));
}

void HUD::Draw(sf::RenderWindow & window) {
	window.draw(*scoreText1);
	window.draw(*scoreText2);
}