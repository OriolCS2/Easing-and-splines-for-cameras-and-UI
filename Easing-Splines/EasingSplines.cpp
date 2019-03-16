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

	return true;
}

void EasingSplines::CreateSpline(int * position, int target_position, int velocity, TypeSpline type, float multiplier)
{
	EaseSplineInfo* info = new EaseSplineInfo(position, target_position, velocity, type, multiplier);

	if (info != nullptr)
		easing_splines.push_back(info);
}

bool EaseSplineInfo::Update(float dt)
{
	bool ret = true;

	if (!HasFinished()) {
		switch (type) {
		case EASE: {
			multiplier = multiplier * multiplier;
		} break;
		default:
			break;
		}
		*position += (velocity*multiplier*dt);
	}
	else
		ret = false;

	return ret;
}

bool EaseSplineInfo::HasFinished()
{
	bool ret = false;

	if (velocity < 0) {
		if (*position <= target_position)
			ret = true;
	}
	else {
		if (*position >= target_position)
			ret = true;
	}

	return ret;
}
