#include "Bullet.h"

Bullet::Bullet() : active(false) {
	bullet.setSize(sf::Vector2f(constant::BULLET_WIDTH, constant::BULLET_HEIGHT));
	bullet.setFillColor(sf::Color::White);
	bullet.setPosition(sf::Vector2f(-200.0f, -200.0f));
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