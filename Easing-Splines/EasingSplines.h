#ifndef __EASINGSPLINES_H__
#define __EASINGSPLINES_H__

#include "j1Module.h"
#include <list>

struct SDL_Texture;
struct SDL_Rect;

struct EaseSplineInfo {

	int * position;
	int duration;
	int initial_pos;
	int time;
	int time_start;
	int velocity;

	float EaseInQuad() {
		return *position * (time /= duration)*time + initial_pos;
	}

	bool Finished() {

		return time <= duration;
	}
};

enum class TypeSpline {

	NONE,
};

class EasingSplines : public j1Module
{
public:

	EasingSplines();

	// Destructor
	virtual ~EasingSplines();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	int EaseInQuad(int time, int initial_pos, int current_pos, int duration) {
		return current_pos * (time /= duration)*time + initial_pos;
	}

public:

	EaseSplineInfo info;
};

#endif 
