#include "Character.h"

Character::Character(int x, int y) {
	player.setSize(sf::Vector2f(30, 30));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setFillColor(sf::Color(245, 147, 51));
	//player.setPosition(400, 560);
	//player.setPosition(400, 40);
	player.setPosition(x, y);
}

Character::~Character() {

}

void Character::Update(float deltaTime, int playerNum) {
	Movement(deltaTime);

	Input(deltaTime, playerNum);
}

void Character::Input(float deltaTime, int playerNum) {

	if (playerNum == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			velocity += deltaTime * 3000.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			velocity -= deltaTime * 3000.0f;
	}

	if (playerNum == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity += deltaTime * 3000.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			velocity -= deltaTime * 3000.0f;
	}


	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//Shoot(deltaTime, window);
	}
	//cooldown -= deltaTime;
	*/
}

void Character::Movement(float deltaTime) {
	
	/* Velocidad maxima del jugador */
	if (velocity > 500.0f)
		velocity = 500.0f;

	if (velocity < -500.0f)
		velocity = -500.0f;


	/* Friccion del jugador */
	if (velocity > 0)
		velocity -= deltaTime * 1000.0f;

	if (velocity < 0)
		velocity += deltaTime * 1000.0f;


	/* Limites del jugador */
	if (player.getPosition().x > 800) {
		player.setPosition(800, player.getPosition().y);
		velocity = 0;
	}
	if (player.getPosition().x < 0) {
		player.setPosition(0, player.getPosition().y);
		velocity = 0;
	}

	velocity = std::floor(velocity * 10 + 0.5f) / 10;

	player.move(deltaTime * velocity, 0);

}

void Character::Draw(sf::RenderWindow & window) {
	window.draw(player);
}

void Character::Shoot(std::vector<Bullet>* bulletVec, int offset) {
		Bullet bullet(sf::Vector2f(5, 30));
		bullet.SetPos(sf::Vector2f(player.getPosition().x, player.getPosition().y + offset));
		bulletVec->push_back(bullet);
}