#include "PlayerTwo.h"

PlayerTwo::PlayerTwo() : delay(0.0f){
	texture = new sf::Texture;
	texture->loadFromFile(constant::P_BLUE);
	player.setSize(sf::Vector2f(constant::PLAYER_WIDTH, constant::PLAYER_HEIGHT));
	player.setTexture(texture);
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setPosition(constant::PLAYER2_SPAWN_X, constant::PLAYER2_SPAWN_Y);

	atkBuffer.loadFromFile(constant::SHOOT_BLUE);

	atk.setBuffer(atkBuffer);
	atk.setVolume(constant::ATK_VOLUME);

	for (int i = 0; i < constant::BULLETS; i++) {
		BulletTwo* bul = new BulletTwo();
		bullets.push_back(bul);
	}
}

PlayerTwo::~PlayerTwo() {
	delete texture;

	for (int i = 0; i < constant::BULLETS; i++)
		delete bullets[i];
}

void PlayerTwo::Input(float deltaTime, bool & shoot) {
	delay += deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity += deltaTime * constant::VELOCITY_MULTIPLIER;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity -= deltaTime * constant::VELOCITY_MULTIPLIER;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) && !shoot) {
		if (delay > constant::INPUT_DELAY) {
			shoot = true;
			atk.play();
			delay = 0.0f;
		}
	}
}

void PlayerTwo::Shoot() {
	int i = 0;

	while (i < bullets.size() && bullets[i]->IsActive() == true)
		i++;

	if (i == bullets.size())
		std::cout << "NO BULLETS, ABORT!" << std::endl;
	else {
		bullets[i]->SetActive(true);
		bullets[i]->SetPos(sf::Vector2f(player.getPosition().x, player.getPosition().y + constant::SHOOT2_OFFSET));
	}
}