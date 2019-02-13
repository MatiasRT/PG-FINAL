#ifndef PLAYERONE_H
#define PLAYERONE_H
#include "Character.h"
#include "BulletOne.h"
class PlayerOne : public Character {
	sf::Texture* texture;

	sf::SoundBuffer atkBuffer;

	sf::Sound atk;

	float delay;
	//std::vector<Bullet*> bullets;
	//std::queue<Bullet*>* poolB;
public:
	PlayerOne();
	~PlayerOne();
	void Input(float deltaTime, bool& shoot) override;
	void Shoot() override;
};
#endif