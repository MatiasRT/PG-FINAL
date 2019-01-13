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

	Character player1(400, 560);
	Character player2(400, 40);

	std::vector<Bullet> vec;

	sf::Clock clock;

	bool isFiring = false;

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			isFiring = true;
		}

		cooldown -= deltaTime;

		/* UPDATES */
		player1.Update(deltaTime, 1);
		player2.Update(deltaTime, 2);

		/* DRAWS */
		window.clear(sf::Color::Black);
		player1.Draw(window);
		player2.Draw(window);

		/* SHOOT */
		/* FALTA ELIMINAR LAS BALAS */
	

		if (isFiring == true) {
			if (cooldown <= 0) {
				cooldown = 0.30f;
				player1.Shoot(&vec);
				isFiring = false;
			}
		}

		for (int i = 0; i < vec.size(); i++) {
			vec[i].Draw(window);
			vec[i].Move(10);
		}

		window.display();
		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}

void Game::End() {

}