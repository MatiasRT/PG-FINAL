#include "Game.h"
#include "Constants.h"

Game::Game() {
	window.create(sf::VideoMode(constant::WINDOW_WIDTH, constant::WINDOW_HEIGHT), "Game", sf::Style::Close);
	window.setFramerateLimit(constant::FRAMERATE);

	if (!font1.loadFromFile("Assets/beef.ttf")) {
		std::cout << "Error: Font1 loadFromFile failed" << std::endl;
	}

	hud = new HUD();
}

Game::~Game() {
	delete hud;
}

void Game::RunGame() {
	state = MENU;
	//state = GAME;

	while (state != EXIT) {
		switch (state) {
		case MENU:
			Menu();
			break;
		case GAME:
			Play();
			break;
		case CONTROLS:
			//Controls();
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

	sf::String menuTextString[3] = { "PLAY", "HOWTO", "EXIT" };

	sf::Text menuText(menuTextString[0], font1, 28);
	menuText.setOrigin(std::round(menuText.getLocalBounds().width / 2), 20);
	menuText.setPosition((800 / 2), 400);
	menuText.setFillColor(sf::Color(245, 147, 51));

	hud->Menu();

	int menuSelect = 0;

	while (state == MENU) {

		sf::Event event;
		while (window.pollEvent(event)) {

			switch (event.type) {
				case sf::Event::Closed:
					state = EXIT;
					break;

				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape) 
						state = EXIT;
				
					if (event.key.code == sf::Keyboard::A) 
						if (menuSelect > 0)
							menuSelect -= 1;
					
					if (event.key.code == sf::Keyboard::D) 
						if (menuSelect < 2)
							menuSelect += 1;
					
					if (event.key.code == sf::Keyboard::Return) 
						if (menuSelect == 0)
							state = GAME;
						else if (menuSelect == 1)
							state = CONTROLS;
							else if (menuSelect == 2)
								state = EXIT;
					break;
			}
		}

		menuText.setString(menuTextString[menuSelect]);

		window.clear(sf::Color::Black);

		window.draw(menuText);
		hud->DrawMenu(window);

		window.display();
	}
}

void Game::Play() {
	std::cout << "Estoy en play" << std::endl;

	/* PLAYERS */
	Character player1(constant::PLAYER1_SPAWN_X, constant::PLAYER1_SPAWN_Y);
	Character player2(constant::PLAYER2_SPAWN_X, constant::PLAYER2_SPAWN_Y);

	/* BULLETS */
	std::vector<Bullet> vec1;
	std::vector<Bullet> vec2;

	/* MISC */
	score1 = score2 = constant::INIT_SCORE;
	sf::Clock clock;
	hud->Game();


	bool isFiring1 = false;
	bool isFiring2 = false;

	while (state == GAME) {

		sf::Event event;
		while (window.pollEvent(event)) {

			switch (event.type) {

				case sf::Event::Closed:
					state = EXIT;
					break;

				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape) {
						state = EXIT;
					}
					if (event.key.code == sf::Keyboard::Return) {
						state = MENU;
					}
					break;
			}
		}

		cooldown1 -= deltaTime;
		cooldown2 -= deltaTime;
		timer -= deltaTime;

		/* UPDATES */
		player1.Update(deltaTime, 1, &isFiring1);
		player2.Update(deltaTime, 2, &isFiring2);
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
			vec1[i].Move(1);	
		}

		for (int i = 0; i < vec2.size(); i++) {
			vec2[i].Draw(window);
			vec2[i].Move(2);
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