#include "Character.h"
#include "Constants.h"

Character::Character() {

	hitBuffer.loadFromFile(constant::HIT_RED);

	hit.setBuffer(hitBuffer);
	hit.setVolume(constant::HIT_VOLUME);

}

Character::~Character() {

}

void Character::Update(float deltaTime, bool& shoot, int& score) {
	Movement(deltaTime);

	Input(deltaTime, shoot);

	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->IsActive())
			bullets[i]->Update();
		if (CollisionManager::Instance()->CheckCollision(player.getPosition(), bullets[i]->GetPos())) {
			hit.play();
			if (score < constant::MAX_SCORE)
				score += constant::HIT_POINTS;
		}
	}
}

void Character::Movement(float deltaTime) {
	
	/* Velocidad maxima del jugador */
	if (velocity > constant::MAX_VELOCITY)
		velocity = constant::MAX_VELOCITY;

	if (velocity < -constant::MAX_VELOCITY)
		velocity = -constant::MAX_VELOCITY;


	/* Friccion del jugador */
	if (velocity > 0)
		velocity -= deltaTime * constant::VELOCITY_FRICTION;

	if (velocity < 0)
		velocity += deltaTime * constant::VELOCITY_FRICTION;


	/* Limites del jugador */
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

/*void Character::Shoot(std::queue<Bullet*>* bulletQ, std::vector<Bullet>& vec, int offset) {
	/*Bullet bullet(sf::Vector2f(constant::BULLER_WIDTH, constant::BULLER_HEIGHT));
	bullet.SetPos(sf::Vector2f(player.getPosition().x, player.getPosition().y + offset));
	bulletVec.push_back(bullet);/

	Bullet* bullet = bulletQ->front();
	bullet->SetActive(true);
	bullet->SetPos(sf::Vector2f(player.getPosition().x, player.getPosition().y + offset));
	vec.push_back(*bullet);
	if(!bulletQ->empty())
		bulletQ->pop();
	else
		std::cout << bulletQ->size() << std::endl;

}*/

/*void Character::CheckCollision(Bullet bullet, int &score) {

	//bool isHit = false;

	if (bullet.GetTop() < player.getPosition().y + player.getSize().y &&
		bullet.GetBottom() > player.getPosition().y &&
		bullet.GetLeft() < player.getPosition().x + player.getSize().x - constant::PLAYER_HEIGHT / 2 &&
		bullet.GetRight() + constant::PLAYER_WIDTH / 2 > player.getPosition().x) {
		//if (!isHit) {
			//isHit = true;
			hit.play();
			//isHit = false;
		//}
		if(score < constant::MAX_SCORE)
			score += constant::HIT_POINTS;
	}
}*/