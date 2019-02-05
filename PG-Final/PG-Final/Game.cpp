#include "Game.h"
#include "Constants.h"

Game::Game() {
	window.create(sf::VideoMode(constant::WINDOW_WIDTH, constant::WINDOW_HEIGHT), constant::GAME_NAME, sf::Style::Close);
	window.setFramerateLimit(constant::FRAMERATE);

	if (!font1.loadFromFile(constant::FONT)) 
		std::cout << "Error: Font1 loadFromFile failed" << std::endl;
	
	hud = new HUD();

	mainMusic.openFromFile(constant::MAIN_MUSIC);
	mainMusic.setVolume(constant::MUSIC_VOLUME);
	mainMusic.play();
	mainMusic.setLoop(true);
}

Game::~Game() {
	delete hud;
}

void Game::RunGame() {
	state = MENU;

	while (state != EXIT) {
		switch (state) {
		case MENU:
			Menu();
			break;
		case GAME:
			Play();
			break;
		case CONTROLS:
			Controls();
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

	sf::Texture arrow;
	if (!arrow.loadFromFile(constant::TEXTURE_ARROW))
		std::cout << "Error: arrow loadFromFile failed" << std::endl;

	sf::Sprite arrowLeft(arrow);
	arrowLeft.setPosition(constant::ARROWLEFT_POSITION_X, constant::ARROWLEFT_POSITION_Y);
	arrowLeft.setScale(-1, 1);

	sf::Sprite arrowRight(arrow);
	arrowRight.setPosition(constant::ARROWRIGHT_POSITION_X, constant::ARROWRIGHT_POSITION_Y);

	sf::String menuTextString[3] = { constant::PLAY, constant::HOW_TO, constant::EXIT };

	sf::Text menuText(menuTextString[0], font1, constant::FONT_SIZE5);
	menuText.setOrigin(std::round(menuText.getLocalBounds().width / 2), 20);
	menuText.setPosition(constant::MENU_TEXT_X, constant::MENU_TEXT_Y);
	menuText.setFillColor(sf::Color::White);

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
		window.draw(arrowLeft);
		window.draw(arrowRight);
		hud->DrawMenu(window);

		window.display();
	}
}

void Game::Play() {

	sf::Texture background;
	if (!background.loadFromFile(constant::BACKGROUND))
		std::cout << "Error: howtoTexture loadFromFile failed" << std::endl;
	sf::Sprite bkg(background);

	/* PLAYERS */
	Character player1(constant::PLAYER1_SPAWN_X, constant::PLAYER1_SPAWN_Y, constant::P_RED);
	Character player2(constant::PLAYER2_SPAWN_X, constant::PLAYER2_SPAWN_Y, constant::P_BLUE);

	/* BULLETS */
	std::vector<Bullet> vec1;
	std::vector<Bullet> vec2;

	/* MISC */
	score1 = score2 = constant::INIT_SCORE;
	sf::Clock clock;
	hud->Game();
	Score score;

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
					if (event.key.code == sf::Keyboard::Escape) 
						state = EXIT;
					if (event.key.code == sf::Keyboard::Return) 
						state = MENU;	
					break;
			}
		}

		cooldown1 -= deltaTime;
		cooldown2 -= deltaTime;
		timer -= deltaTime;

		/* UPDATES */
		player1.Update(deltaTime, constant::PLAYER_RED, isFiring1);
		player2.Update(deltaTime, constant::PLAYER_BLUE, isFiring2);
		hud->Update(score1, score2);
		score.Update(timer, score1, score2, winner, state);

		/* SHOOT */
		/* FALTA ELIMINAR LAS BALAS */
		if (isFiring1 == true) {
			if (cooldown1 <= 0) {
				cooldown1 = constant::COOLDOWN;
				player1.Shoot(vec1, constant::SHOOT1_OFFSET);
				isFiring1 = false;
			}
		}

		if (isFiring2 == true) {
			if (cooldown2 <= 0) {
				cooldown2 = constant::COOLDOWN;
				player2.Shoot(vec2, constant::SHOOT2_OFFSET);
				isFiring2 = false;
			}
		}

		/* DRAWS */
		window.clear(sf::Color::Black);
		window.draw(bkg);
		player1.Draw(window);
		player2.Draw(window);
		hud->DrawGame(window);

		for (int i = 0; i < vec1.size(); i++) {
			vec1[i].Draw(window);
			vec1[i].Move(constant::PLAYER_RED);	
		}

		for (int i = 0; i < vec2.size(); i++) {
			vec2[i].Draw(window);
			vec2[i].Move(constant::PLAYER_BLUE);
		}

		/* COLLISIONS */
		for (int i = 0; i < vec1.size(); i++) {
			player2.CheckCollision(vec1[i], score1);	////ACORDARSE DE HACER LO DE LA REFERENCIA BIEN
		}

		for (int i = 0; i < vec2.size(); i++) {
			player1.CheckCollision(vec2[i], score2);
		}

		window.display();
		deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
	}
}

void Game::Controls() {

	sf::Texture howtoTexture;
	if (!howtoTexture.loadFromFile(constant::TEXTURE_HOWTO))
		std::cout << "Error: howtoTexture loadFromFile failed" << std::endl;
	sf::Sprite howto(howtoTexture);

	while (state == CONTROLS) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				state = EXIT;
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Return)
					state = MENU;
				break;
			}
		}

		window.clear(sf::Color::Black);
		window.draw(howto);

		window.display();
	}
}

void Game::GameOver(int winner) {

	std::string pWin;
	int finalScore;
	switch (winner) {
		case 1:
			pWin = constant::PLAYER1;
			finalScore = score1;
			break;
		case 2:
			pWin = constant::PLAYER2;
			finalScore = score2;
			break;
		case 3:
			pWin = constant::TIE;
			finalScore = 0;
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
					if (event.key.code == sf::Keyboard::Return) 
						state = MENU;
					break;
			}
		}

		window.clear(sf::Color::Black);

		hud->DrawOver(window);

		window.display();
	}
}