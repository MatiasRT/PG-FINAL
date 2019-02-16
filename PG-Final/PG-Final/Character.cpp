#include "Character.h"

Character::Character() {

	hitBuffer.loadFromFile(constant::HIT_RED);

	hit.setBuffer(hitBuffer);
	hit.setVolume(constant::HIT_VOLUME);
}

Character::~Character() {
	for (int i = 0; i < bullets.size(); i++)
		delete bullets[i];
}

void Character::Update(sf::Vector2f playerPos, float deltaTime, int& score) {
	Movement(deltaTime);

	Input(deltaTime);

	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->IsActive())
			bullets[i]->Update();
		if (CollisionManager::Instance()->CheckCollision(playerPos, bullets[i]->GetPos())) {
			bullets[i]->SetActive(false);
			hit.play();
			if (score < constant::MAX_SCORE)
				score += constant::HIT_POINTS;
		}
	}
}

void Character::Movement(float deltaTime) {

	if (velocity > constant::MAX_VELOCITY)
		velocity = constant::MAX_VELOCITY;

	if (velocity < -constant::MAX_VELOCITY)
		velocity = -constant::MAX_VELOCITY;

	if (velocity > 0)
		velocity -= deltaTime * constant::VELOCITY_FRICTION;

	if (velocity < 0)
		velocity += deltaTime * constant::VELOCITY_FRICTION;

	if (player.getPosition().x > constant::WINDOW_MAX_X) {
		player.setPosition(constant::WINDOW_MAX_X, player.getPosition().y);
		velocity = 0;
	}

	if (player.getPosition().x < constant::WINDOW_MIN_X) {
		player.setPosition(constant::WINDOW_MIN_X, player.getPosition().y);
		velocity = 0;
	}

	player.move(deltaTime * velocity, 0);
}

void Character::Draw(sf::RenderWindow & window) {
	window.draw(player);
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->IsActive())
			bullets[i]->Draw(window);
	}
}