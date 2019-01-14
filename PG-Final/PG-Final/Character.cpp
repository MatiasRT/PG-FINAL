#include "Character.h"
#include "Constants.h"

Character::Character(int x, int y) {
	player.setSize(sf::Vector2f(constant::PLAYER_WIDTH, constant::PLAYER_HEIGHT));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setFillColor(sf::Color(245, 147, 51));
	player.setPosition(x, y);
}

Character::~Character() {

}

void Character::Update(float deltaTime, int playerNum, bool* shoot) {
	Movement(deltaTime);

	Input(deltaTime, playerNum, shoot);
}

void Character::Input(float deltaTime, int playerNum, bool* shoot) {

	if (playerNum == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			velocity += deltaTime * 3000.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			velocity -= deltaTime * 3000.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			*shoot = true;
	}

	if (playerNum == 2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity += deltaTime * 3000.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			velocity -= deltaTime * 3000.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) 
			*shoot = true;
	}
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
	if (player.getPosition().x > constant::WINDOW_MAX_X) {
		player.setPosition(constant::WINDOW_MAX_X, player.getPosition().y);
		velocity = 0;
	}
	if (player.getPosition().x < constant::WINDOW_MIN_X) {
		player.setPosition(constant::WINDOW_MIN_X, player.getPosition().y);
		velocity = 0;
	}

	velocity = std::floor(velocity * 10 + 0.5f) / 10;

	player.move(deltaTime * velocity, 0);

}

void Character::Draw(sf::RenderWindow & window) {
	window.draw(player);
}

void Character::Shoot(std::vector<Bullet>* bulletVec, int offset) {
	Bullet bullet(sf::Vector2f(constant::BULLER_WIDTH, constant::BULLER_HEIGHT));
	bullet.SetPos(sf::Vector2f(player.getPosition().x, player.getPosition().y + offset));
	bulletVec->push_back(bullet);
}

void Character::CheckCollision(Bullet bullet, int *score) {
	if (bullet.GetTop() < player.getPosition().y + player.getSize().y &&
		bullet.GetBottom() > player.getPosition().y &&
		bullet.GetLeft() < player.getPosition().x + player.getSize().x - constant::PLAYER_HEIGHT / 2 &&  // 15 es la mitad del player
		bullet.GetRight() + constant::PLAYER_WIDTH / 2 > player.getPosition().x) {
		*score += constant::HIT_POINTS;
		std::cout << "Colision y score:" << *score << std::endl;
	}
}