#ifndef PLAYERTWO_H
#define PLAYERTWO_H
#include "Character.h"
#include "BulletTwo.h"
class PlayerTwo : public Character {
	sf::Texture* texture;

	sf::SoundBuffer atkBuffer;

	sf::Sound atk;

	float delay;
	//std::vector<Bullet*> bullets;
public:
	PlayerTwo();
	~PlayerTwo();
	void Input(float deltaTime, bool& shoot) override;
	void Shoot() override;
};
#endif