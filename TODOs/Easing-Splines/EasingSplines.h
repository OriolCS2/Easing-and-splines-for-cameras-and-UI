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
	EASE_IN_OUT_EXPO,
	EASE_OUT_ELASTIC,
	EASE_OUT_CUBIC,
	EASE_IN_CIRC,


	NONE
};

struct EaseFunctions {
	int EaseOutQuint(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
	int Ease(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
	int EaseInOutBack(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
	int EaseOutQuart(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
	int EaseInQuad(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
	int EaseInOutExpo(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
	int EaseOutElastic(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
	int EaseOutCubic(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
	int EaseInCirc(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel);
};

struct EaseSplineInfo {

	int * position = nullptr;
	int initial_position = 0;
	int distance_to_travel = 0;
	float time_to_travel = 0.0F;
	float time_started = 0.0F;
	TypeSpline type = TypeSpline::NONE;

	EaseFunctions ease_function;
	bool Update(float dt);

	EaseSplineInfo(int * position, const int &target_position, const float &time_to_travel, const TypeSpline &type) {
		// TODO 1: Create the constructor, 6 lines are needed

		


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

	void CreateSpline(int * position, const int &target_position, const float &time_to_travel, const TypeSpline &type);


private:

	std::list<EaseSplineInfo*> easing_splines;


};

#endif