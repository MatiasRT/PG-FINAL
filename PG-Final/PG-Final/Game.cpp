#include "Game.h"

Game::Game() {
	window.create(sf::VideoMode(800, 600), "Game", sf::Style::Close);
	window.setFramerateLimit(60);
}

Game::~Game() {

}

void Game::RunGame() {
	//state = MENU;
	state = GAME;

	while (state != EXIT) {
		switch (state) {
		case MENU:
			Menu();
			break;
		case GAME:
			Play();
			break;
		case EXIT:
			break;
		}
	}
}

void Game::Menu() {
	std::cout << "Estoy en menu" << std::endl;
}

void Game::Play() {
	std::cout << "Estoy en play" << std::endl;
}

void Game::Exit() {

}