#include "Music.h"

Music::Music(const char* path, ChooseMusic chooseMusic)
{

	al_reserve_samples(1);

	if(chooseMusic == ChooseMusic::SAMPLE)
		this->soundEffect = al_load_sample(path);
	else {
		this->song = al_load_sample(path);
		this->songInstance = al_create_sample_instance(this->song);
		al_set_sample_instance_playmode(this->songInstance, ALLEGRO_PLAYMODE_LOOP);
		al_attach_sample_instance_to_mixer(this->songInstance, al_get_default_mixer());
	}
	



	
}

Music::~Music()
{
	if (song) {
		al_destroy_sample(song);
		al_destroy_sample_instance(songInstance);
	}
	if(soundEffect)
		al_destroy_sample(soundEffect);
	
}

void Music::shotSound()
{
	if(soundEffect)
		al_play_sample(soundEffect, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}

void Music::playMusic()
{
	if (song)
		al_play_sample_instance(songInstance);
}