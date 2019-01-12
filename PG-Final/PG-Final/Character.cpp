#include "Character.h"

Character::Character() {
	player.setSize(sf::Vector2f(30, 30));
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	player.setFillColor(sf::Color(245, 147, 51));
	player.setPosition(400, 560);
}

Character::~Character() {

}

void Character::Update(float deltaTime, sf::RenderWindow & window) {
	/* Input del jugador */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity += deltaTime * 3000.0f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity -= deltaTime * 3000.0f;
	
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//Shoot(deltaTime, window);
	}
	//cooldown -= deltaTime;
	*/

	

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

void Character::Shoot(float deltaTime, sf::RenderWindow & window) {
	
}