#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"
#include <iostream>

enum States {
	MENU,
	GAME,
	OVER,
	EXIT
};

class Game {

public:
	Game();
	~Game();

	sf::RenderWindow window;
	sf::Font font1;

	States state;

	float cooldown1;
	float cooldown2;
	float timer;
	float deltaTime = 0.0f;
	int score1;
	int score2;
	int winner;

	void RunGame();

	void Menu();
	void Play();
	void GameOver(int winner);
};