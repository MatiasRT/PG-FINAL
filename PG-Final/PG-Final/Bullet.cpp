#include "Bullet.h"

Bullet::Bullet(sf::Vector2f size) {
	bullet.setSize(size);
	bullet.setFillColor(sf::Color(245, 147, 51));
}

Bullet::~Bullet() {

}

void Bullet::Move(int speed, int playerNum) {
	switch (playerNum) {
		case 1:
			bullet.move(0, -speed);
			break;
		case 2:
			bullet.move(0, speed);
			break;
	}
}

void Bullet::Draw(sf::RenderWindow & window) {
	window.draw(bullet);
}

void Bullet::SetPos(sf::Vector2f pos) {
	bullet.setPosition(pos);
}