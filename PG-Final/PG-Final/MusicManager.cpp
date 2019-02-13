#include "MusicManager.h"

MusicManager::MusicManager() {
	mainMusic = new sf::Music;
}

MusicManager::~MusicManager() {
	delete mainMusic;
}

void MusicManager::PlayMusic() {
	mainMusic->openFromFile(constant::MAIN_MUSIC);
	mainMusic->setVolume(constant::MUSIC_VOLUME);
	mainMusic->play();
	mainMusic->setLoop(true);
}

void MusicManager::StopMusic() {
	mainMusic->stop();
	mainMusic->setLoop(false);
}