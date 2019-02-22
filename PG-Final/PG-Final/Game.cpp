#include "Game.h"
#include "Constants.h"

Game::Game() {
	window.create(sf::VideoMode(constant::WINDOW_WIDTH, constant::WINDOW_HEIGHT), constant::GAME_NAME, sf::Style::Close);
	window.setFramerateLimit(constant::FRAMERATE);

	if (!font1.loadFromFile(constant::FONT)) 
		std::cout << "Error: Font1 loadFromFile failed" << std::endl;
	
	hud = new HUD();
	music = new MusicManager();
	music->PlayMusic();
}

Game::~Game() {
	delete hud;
	delete music;
	delete player1;
	delete player2;
	delete score;
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
	window.close();
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

	CollisionManager::Instance();

	sf::Texture background;
	if (!background.loadFromFile(constant::BACKGROUND))
		std::cout << "Error: howtoTexture loadFromFile failed" << std::endl;
	sf::Sprite bkg(background);

	/* PLAYERS */
	player1 = new PlayerOne();
	player2 = new PlayerTwo();

	/* MISC */
	score1 = score2 = constant::INIT_SCORE;
	sf::Clock clock;
	hud->Game();
	score = new Score();

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

		timer -= deltaTime;

		/* UPDATES */
		player1->Update(player2->GetPos(), deltaTime, score1);
		player2->Update(player1->GetPos(), deltaTime, score2);
		hud->Update(score1, score2);
		score->Update(timer, score1, score2, winner, state);

		/* DRAWS */
		window.clear(sf::Color::Black);
		window.draw(bkg);
		player1->Draw(window);
		player2->Draw(window);
		hud->DrawGame(window);

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