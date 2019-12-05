#include "Engine.h"
#include <Windows.h>
#include <iostream>

Engine* Engine::instance = 0;
Engine::Engine()
{
	this->display = al_create_display(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		exit(0);
	}
	al_set_new_display_flags(ALLEGRO_FULLSCREEN | ALLEGRO_MAXIMIZED);
	al_set_window_title(this->display, "Game");


	this->event_queue = al_create_event_queue();

	al_register_event_source(this->event_queue, al_get_keyboard_event_source());
	al_register_event_source(this->event_queue, al_get_mouse_event_source());


	FPS[0] = 30;
	FPS[1] = 15;
	FPS[2] = 70;
	FPS[3] = 1;

	for (int i = 0; i < 4; i++) {
		ALLEGRO_TIMER* timmer = al_create_timer(1.0 / FPS[i]);
		timmerVector.push_back(timmer);
		al_register_event_source(this->event_queue, al_get_timer_event_source(timmer));

	}


	startTimers();

}

Engine::~Engine()
{
	for (int i = 0; i < 4; i++) {
		al_destroy_timer(timmerVector[i]);
	}
	al_destroy_event_queue(this->event_queue);

	al_destroy_display(this->display);
	cout << "DESTTTTTTRUKTOR Z EEEEENGINEEEE !!!" << endl;
}

Engine* Engine::getInstance()
{
	if (instance == 0)
	{
		instance = new Engine();
	}

	return instance;
}

ALLEGRO_DISPLAY* Engine::returnDisplay()
{
	return display;
}



void Engine::startTimers()
{
	for (int i = 0; i < 4; i++)
		al_start_timer(this->timmerVector[i]);

}

void Engine::stopTimers()
{
	for (int i = 0; i < 4; i++)
		al_stop_timer(this->timmerVector[i]);
}