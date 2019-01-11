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
		case END:
			End();
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

	Character player;

	sf::Clock clock;

	while (state == GAME) {

		sf::Event evt;
		while (window.pollEvent(evt)) {

			switch (evt.type) {

				case sf::Event::Closed:
					state = EXIT;
					break;

				case sf::Event::KeyPressed:
					if (evt.key.code == sf::Keyboard::Escape) {
						state = EXIT;
					}
					if (evt.key.code == sf::Keyboard::Return) {
						state = MENU;
					}
					break;
			}
		}

		/* UPDATES */
		player.Update(deltaTime);

		/* DRAWS */
		window.clear(sf::Color::Black);
		player.Draw(window);

		window.display();
		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}

void Game::End() {

}