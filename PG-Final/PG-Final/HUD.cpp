#include "HUD.h"
#include "Constants.h"

HUD::HUD() {
	if (!font1.loadFromFile("Assets/beef.ttf")) 
		std::cout << "Error: Font1 loadFromFile failed" << std::endl;
}

HUD::~HUD() {
	delete scoreText1;
	delete scoreText2;
	delete title1;
	delete title2;
	delete title3;
	delete control;
	delete arrowLeft;
	delete arrowRight;
	delete menu;
	delete winText;
	delete playerW;
	delete score;
	delete restart;
}

void HUD::Menu() {

	title1 = new sf::Text("RED", font1, 50);
	title1->setOrigin(std::round(title1->getLocalBounds().width / 2), 20);
	title1->setPosition(165, 120);
	title1->setFillColor(sf::Color::Red);

	title2 = new sf::Text("VS.", font1, 50);
	title2->setOrigin(std::round(title2->getLocalBounds().width / 2), 20);
	title2->setPosition(365, 120);
	title2->setFillColor(sf::Color::White);

	title3 = new sf::Text(" BLUE", font1, 50);
	title3->setOrigin(std::round(title3->getLocalBounds().width / 2), 20);
	title3->setPosition(565, 120);
	title3->setFillColor(sf::Color::Blue);

	control = new sf::Text("Press ENTER to select", font1, 12);
	control->setOrigin(std::round(control->getLocalBounds().width / 2), 20);
	control->setPosition((800 / 2), 440);
	control->setFillColor(sf::Color::White);

	sf::Texture arrow;
	arrow.loadFromFile("path a la imagen");

	arrowLeft = new sf::Sprite(arrow);
	arrowLeft->setOrigin(arrowLeft->getLocalBounds().width / 2, 4);
	arrowLeft->setPosition((800 / 2 + 50), 400);

	arrowRight = new sf::Sprite(arrow);
	arrowRight->setOrigin(arrowRight->getLocalBounds().width / 2, 4);
	arrowRight->setPosition((800 / 2 - 45), 400);
	arrowRight->setScale(-1, 1);
}

void HUD::Game() {
	scoreText1 = new sf::Text("0", font1, constant::FONT_SIZE1);
	scoreText1->setOrigin(sf::Vector2f(scoreText1->getLocalBounds().width / 2, 0));
	scoreText1->setPosition(360, 320);
	scoreText1->setFillColor(sf::Color::Red);

	scoreText2 = new sf::Text("0", font1, constant::FONT_SIZE1);
	scoreText2->setOrigin(sf::Vector2f(scoreText2->getLocalBounds().width / 2, 0));
	scoreText2->setPosition(360, 280);
	scoreText2->setFillColor(sf::Color::Blue);
}

void HUD::Over(std::string pWin, int finalScore) {
	winText = new sf::Text("The Winner Is", font1, constant::FONT_SIZE2);
	winText->setOrigin(std::round(winText->getLocalBounds().width / 2), 20);
	winText->setPosition((800 / 2), 80);
	winText->setFillColor(sf::Color::White);

	playerW = new sf::Text(pWin, font1, constant::FONT_SIZE3);
	playerW->setOrigin(std::round(playerW->getLocalBounds().width / 2), 20);
	playerW->setPosition((800 / 2), 250);
	if(pWin == "PLAYER 1")
		playerW->setFillColor(sf::Color::Red);
	else playerW->setFillColor(sf::Color::Blue);

	score = new sf::Text(std::to_string(finalScore), font1, constant::FONT_SIZE3);
	score->setOrigin(std::round(score->getLocalBounds().width / 2), 20);
	score->setPosition((800 / 2), 300);
	if (pWin == "PLAYER 1")
		score->setFillColor(sf::Color::Red);
	else score->setFillColor(sf::Color::Blue);

	menu = new sf::Text("Press ENTER to continue", font1, constant::FONT_SIZE4);
	menu->setOrigin(std::round(menu->getLocalBounds().width / 2), 20);
	menu->setPosition((800 / 2), 500);
	menu->setFillColor(sf::Color::White);

	restart = new sf::Text("Press R to restart", font1, constant::FONT_SIZE4);
	restart->setOrigin(std::round(restart->getLocalBounds().width / 2), 20);
	restart->setPosition((800 / 2), 550);
	restart->setFillColor(sf::Color::White);
}

void HUD::Update(int score1, int score2) {
	scoreText1->setString(std::to_string(score1));
	scoreText2->setString(std::to_string(score2));
}

void HUD::DrawMenu(sf::RenderWindow & window) {
	window.draw(*title1);
	window.draw(*title2);
	window.draw(*title3);
	window.draw(*control);
	//window.draw(*arrowLeft);
	//window.draw(*arrowRight);
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