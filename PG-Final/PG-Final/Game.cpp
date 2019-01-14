#include "Game.h"

Game::Game() {
	window.create(sf::VideoMode(800, 600), "Game", sf::Style::Close);
	window.setFramerateLimit(60);

	if (!font1.loadFromFile("Assets/beef.ttf")) {
		std::cout << "Error: Font1 loadFromFile failed" << std::endl;
	}
}

Game::~Game() {
	delete hud;
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
		case OVER:
			GameOver(winner);
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

	/* PLAYERS */
	Character player1(400, 560);
	Character player2(400, 40);

	/* BULLETS */
	std::vector<Bullet> vec1;
	std::vector<Bullet> vec2;

	/* MISC */
	score1 = 50000;
	score2 = 50000;
	sf::Clock clock;
	hud = new HUD();
	hud->Game();


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
		timer -= deltaTime;

		/* UPDATES */
		player1.Update(deltaTime, 1);
		player2.Update(deltaTime, 2);
		hud->Update(score1, score2);

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
		hud->DrawGame(window);

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
			player2.CheckCollision(vec1[i], &score1);
		}

		for (int i = 0; i < vec2.size(); i++) {
			player1.CheckCollision(vec2[i], &score2);
		}

		/* SCORE MANAGER */
		/* FALTA PROGRAMAR EMPATE */
		if (timer <= 0) {
			timer = 0.22f;
			score1 -= 500;
			score2 -= 500;
		}

		if (score1 < 0) {
			winner = 2;
			state = OVER;
		}
		
		if (score2 < 0) {
			winner = 1;
			state = OVER;
		}

		window.display();
		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}

void Game::GameOver(int winner) {

	std::string pWin;
	int finalScore;
	switch (winner) {
		case 1:
			pWin = "PLAYER 1";
			finalScore = score1;
			break;
		case 2:
			pWin = "PLAYER 2";
			finalScore = score2;
			break;
	}
	hud = new HUD;

	hud->Over(pWin, finalScore);

	while (state == OVER) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					state = EXIT;
					break;

				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Return) {
						state = MENU;
					}
					break;
			}
		}

		window.clear(sf::Color(15, 15, 15));

		hud->DrawOver(window);

		window.display();
	}
}