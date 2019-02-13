#include "Bullet.h"
#include "Constants.h"

Bullet::Bullet() {
	bullet.setSize(sf::Vector2f(constant::BULLER_WIDTH, constant::BULLER_HEIGHT));
	bullet.setFillColor(sf::Color::White);
	bullet.setPosition(sf::Vector2f(-200.0f, -200.0f));
	active = false;
}

Bullet::~Bullet() {

}

void Bullet::Update() {
	Move();
	CheckBoundaries();
}

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
	bullet.setPosition(sf::Vector2f(-200.0f, -200.0f));
}