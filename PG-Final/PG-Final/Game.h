#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Bullet.h"
#include <iostream>

enum States {
	MENU,
	GAME,
	END,
	EXIT
};

class Game {

public:
	Game();
	~Game();

	sf::RenderWindow window;
	States state;
	float cooldown;

	void RunGame();

	void Menu();
	void Play();
	void End();

	float deltaTime = 0.0f;
};