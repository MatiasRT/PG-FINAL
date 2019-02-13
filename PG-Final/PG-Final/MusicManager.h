#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H
#include "Constants.h"
#include <SFML/Audio.hpp>
class MusicManager {
private:
	sf::Music* mainMusic;
public:
	MusicManager();
	~MusicManager();
	void PlayMusic();
	void StopMusic();
};
#endif