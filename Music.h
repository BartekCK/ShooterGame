#pragma once
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

enum class ChooseMusic {
	SAMPLE,
	MUSIC
};
class Music
{
	ALLEGRO_SAMPLE* soundEffect = NULL;
	ALLEGRO_SAMPLE* song = NULL;
	ALLEGRO_SAMPLE_INSTANCE* songInstance = NULL;

public:
	Music(const char* path, ChooseMusic chooseMusic);
	~Music();

	void shotSound();
	void playMusic();
};
