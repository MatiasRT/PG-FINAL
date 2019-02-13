#include "Bullet.h"
#include "Constants.h"

Bullet::Bullet() {
	bullet.setSize(sf::Vector2f(constant::BULLER_WIDTH, constant::BULLER_HEIGHT));
	bullet.setFillColor(sf::Color::White);
	active = false;
}

Bullet::~Bullet() {

}

void Bullet::Update() {
	Move();
	CheckBoundaries();
}

/*void Bullet::Move(int playerNum) {
	//active = true;
	switch (playerNum) {
		case 1:
			bullet.move(constant::BULLER_SPEED_X, -constant::BULLET_SPEED_Y);
			break;
		case 2:
			bullet.move(constant::BULLER_SPEED_X, constant::BULLET_SPEED_Y);
			break;
	}
	CheckBoundaries(playerNum);
}

void Bullet::CheckBoundaries(int playerNum) {
	switch (playerNum) {
		case 1:
			if (bullet.getPosition().y < -50)
				active = false;
			break;
		case 2:
			if (bullet.getPosition().y > 650)
				active = false;
			break;
	}
}*/

void Bullet::Draw(sf::RenderWindow & window) {
	window.draw(bullet);
}

void Bullet::SetPos(sf::Vector2f pos) {
	bullet.setPosition(pos);
}

bool Bullet::IsActive() {
	return active;
}

void Bullet::SetActive(bool isActive) {
	active = isActive;
}


