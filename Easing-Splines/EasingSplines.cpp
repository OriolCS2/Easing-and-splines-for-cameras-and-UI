#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "EasingSplines.h"
#include <string>
#include "p2Log.h"

EasingSplines::EasingSplines() : j1Module()
{
	name.assign("easingsplines");
	
}

// Destructor
EasingSplines::~EasingSplines()
{

}

// Called each loop iteration
bool EasingSplines::Update(float dt)
{
	std::list<EaseSplineInfo*>::iterator item = easing_splines.begin();

	for (; item != easing_splines.end(); ++item) {
		if (*item != nullptr) {
			if (!(*item)->Update(dt)) {
				easing_splines.erase(item);
				delete(*item);
				(*item) = nullptr;
			}
		}
	}

	return true;
}

// Called before quitting
bool EasingSplines::CleanUp()
{
	LOG("Freeing scene");

	std::list<EaseSplineInfo*>::iterator item = easing_splines.begin();

	for (; item != easing_splines.end(); ++item) {
		if (*item != nullptr) {
			easing_splines.erase(item);
			delete(*item);
			(*item) = nullptr;
		}
	}

	easing_splines.clear();

	return true;
}

void EasingSplines::CreateSpline(int * position, int target_position, int time_to_travel, TypeSpline type)
{
	EaseSplineInfo* info = new EaseSplineInfo(position, target_position, time_to_travel, type);

	info->time_started = SDL_GetTicks();

	if (info != nullptr)
		easing_splines.push_back(info);
}

bool EaseSplineInfo::Update(float dt)
{
	bool ret = true;

	float time_passed = SDL_GetTicks() - time_started;

	if (time_passed < time_to_travel) {
		switch (type) {
		case EASE: {
			*position = distance_to_travel * (time_passed / time_to_travel) + initial_position;    
			LOG("time_passed: %f", time_passed);
		} break;
		default:
			break;
		}
	}
	else 
		ret = false;
	
	return ret;
}

