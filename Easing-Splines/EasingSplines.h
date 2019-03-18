#ifndef __EASINGSPLINES_H__
#define __EASINGSPLINES_H__

#include "j1Module.h"
#include <list>
#include "SDL/include/SDL_timer.h"

struct SDL_Texture;
struct SDL_Rect;


enum TypeSpline {

	EASE,
	EASE_OUT_QUINT,
	EASE_IN_OUT_BACK,

	NONE
};

struct EaseSplineInfo
{
	int * position;
	TypeSpline type;
	int initial_position;
	int distance_to_travel;
	int time_to_travel;
	int time_started;

	bool Update(float dt);

	EaseSplineInfo(int * position, int target_position, int time_to_travel, TypeSpline type) {
		this->position = position;
		this->initial_position = *position;
		this->distance_to_travel = target_position - *position;
		this->type = type;
		this->time_to_travel = time_to_travel;
		time_started = SDL_GetTicks();
	}


};
class EasingSplines : public j1Module
{
public:

	EasingSplines();

	// Destructor
	virtual ~EasingSplines();

	// Called each loop iteration
	bool Update(float dt);

	// Called before quitting
	bool CleanUp();

	void CreateSpline(int * position, int target_position, int time_to_travel, TypeSpline type);

private:




	std::list<EaseSplineInfo*> easing_splines;


public:



};

#endif 
