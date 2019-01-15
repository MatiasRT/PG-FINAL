#include "Bullet.h"
#include "Constants.h"

Bullet::Bullet(sf::Vector2f size) {
	bullet.setSize(size);
	bullet.setFillColor(sf::Color::White);
}

Bullet::~Bullet() {

}

void Bullet::Move(int playerNum) {
	switch (playerNum) {
		case 1:
			bullet.move(constant::BULLER_SPEED_X, -constant::BULLET_SPEED_Y);
			break;
		case 2:
			bullet.move(constant::BULLER_SPEED_X, constant::BULLET_SPEED_Y);
			break;
	}
}

void Bullet::Draw(sf::RenderWindow & window) {
	window.draw(bullet);
}

void Bullet::SetPos(sf::Vector2f pos) {
	bullet.setPosition(pos);
}