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
		player.Update(deltaTime, window);

		/* DRAWS */
		window.clear(sf::Color::Black);
		player.Draw(window);

		/* SHOOT */
		/* FALTA ELIMINAR LAS BALAS */
		if (isFiring == true) {
			if (cooldown <= 0) {
				cooldown = 0.30f;
				Bullet bullet(sf::Vector2f(5, 30));
				bullet.SetPos(sf::Vector2f(player.GetX(), player.GetY() - 30));
				vec.push_back(bullet);
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