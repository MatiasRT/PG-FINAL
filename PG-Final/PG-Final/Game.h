#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "PlayerOne.h"
#include "PlayerTwo.h"
#include "HUD.h"
#include "States.h"
#include "Score.h"
#include "MusicManager.h"
#include <iostream>

class Game {
private:
	States state;
	HUD* hud;
	MusicManager* music;
	Score* score;

	PlayerOne* player1;
	PlayerTwo* player2;

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
	void Controls();
	void GameOver(int winner);
};
#endif