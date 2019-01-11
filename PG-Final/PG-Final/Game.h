#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum States {
	MENU,
	GAME,
	EXIT
};

class Game {

public:
	Game();
	~Game();

	sf::RenderWindow window;
	States state;

	void RunGame();

	void Menu();
	void Play();
	void Exit();
};