#ifndef __EASINGSPLINES_H__
#define __EASINGSPLINES_H__

#include "j1Module.h"
#include <list>
#include "SDL/include/SDL_timer.h"

struct SDL_Texture;
struct SDL_Rect;


enum class TypeSpline {

	EASE,
	EASE_OUT_QUINT,
	EASE_IN_OUT_BACK,
	EASE_OUT_QUART,
	EASE_IN_QUAD,


	NONE
};

struct EaseFunctions {
	int EaseOutQuint(float time_passed, int initial_position, int distance_to_travel, float time_to_travel);
	int Ease(float time_passed, int initial_position, int distance_to_travel, float time_to_travel);
	int EaseInOutBack(float time_passed, int initial_position, int distance_to_travel, float time_to_travel);
	int EaseOutQuart(float time_passed, int initial_position, int distance_to_travel, float time_to_travel);
	int EaseInQuad(float time_passed, int initial_position, int distance_to_travel, float time_to_travel);
};

struct EaseSplineInfo {

	int * position;
	int initial_position;
	int distance_to_travel;

	float time_to_travel;
	float time_started;

	TypeSpline type;
	EaseFunctions ease_function;

	bool Update(float dt);

	EaseSplineInfo(int * position, const int target_position, const float time_to_travel, TypeSpline type) {
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

	void CreateSpline(int * position, int target_position, const float time_to_travel, TypeSpline type);


private:

	std::list<EaseSplineInfo*> easing_splines;


};

#endif