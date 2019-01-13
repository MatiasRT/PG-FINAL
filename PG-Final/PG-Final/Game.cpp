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

	std::vector<Bullet> vec1;
	std::vector<Bullet> vec2;

	sf::Clock clock;

	bool isFiring1 = false;
	bool isFiring2 = false;

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

		/* SHOOT INPUTS */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			isFiring1 = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) {
			isFiring2 = true;
		}

		cooldown1 -= deltaTime;
		cooldown2 -= deltaTime;

		/* UPDATES */
		player1.Update(deltaTime, 1);
		player2.Update(deltaTime, 2);

		/* SHOOT */
		/* FALTA ELIMINAR LAS BALAS */
		if (isFiring1 == true) {
			if (cooldown1 <= 0) {
				cooldown1 = 0.30f;
				player1.Shoot(&vec1, -30);
				isFiring1 = false;
			}
		}

		if (isFiring2 == true) {
			if (cooldown2 <= 0) {
				cooldown2 = 0.30f;
				player2.Shoot(&vec2, 10);
				isFiring2 = false;
			}
		}

		/* DRAWS */
		window.clear(sf::Color::Black);
		player1.Draw(window);
		player2.Draw(window);

		for (int i = 0; i < vec1.size(); i++) {
			vec1[i].Draw(window);
			vec1[i].Move(10, 1);	
		}

		for (int i = 0; i < vec2.size(); i++) {
			vec2[i].Draw(window);
			vec2[i].Move(10, 2);
		}

		/* COLLISIONS */
		for (int i = 0; i < vec1.size(); i++) {
			player2.CheckCollision(vec1[i]);
		}

		for (int i = 0; i < vec2.size(); i++) {
			player1.CheckCollision(vec2[i]);
		}

		window.display();
		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}

void Game::End() {

}