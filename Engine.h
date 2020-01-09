#pragma once
#include <allegro5/allegro.h>
#include <vector>
#include <string>

enum class DifficultyLevel {
	EASY = 8,
	MEDIUM = 6,
	HARD = 3,
};

using namespace std;

class Engine
{
	ALLEGRO_DISPLAY* display = NULL;

	int FPS[6];
	static Engine* instance;

	

	Engine();
public:
	~Engine();

	static DifficultyLevel difficultyLevel;
	static string playerOne;
	static string playerTwo;
	static int framesOne;
	static int framesTwo;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	vector <ALLEGRO_TIMER*> timmerVector;


	static Engine* getInstance();
	ALLEGRO_DISPLAY* returnDisplay();
	void startTimers();
	void stopTimers();
};