#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"
#include "HUD.h"
#include <iostream>

enum States {
	MENU,
	GAME,
	OVER,
	EXIT
};

class Game {
private:
	States state;
	HUD* hud;

	float cooldown1;
	float cooldown2;
	float timer;
	int winner;

public:
	Game();
	~Game();

	sf::RenderWindow window;
	sf::Font font1;

	float deltaTime = 0.0f;
	int score1;
	int score2;
	
	void RunGame();
	void Menu();
	void Play();
	void GameOver(int winner);
};