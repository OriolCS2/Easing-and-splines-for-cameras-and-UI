#ifndef __EASINGSPLINES_H__
#define __EASINGSPLINES_H__

#include "j1Module.h"
#include <list>

struct SDL_Texture;
struct SDL_Rect;


enum TypeSpline {

	EASE,

	NONE
};

struct EaseSplineInfo
{
	int * position;
	int target_position;
	int velocity;
	TypeSpline type;
	float multiplier;

	EaseSplineInfo(int * position, int target_position, int velocity, TypeSpline type, float multiplier = 1.0f) {
		this->position = position;
		this->target_position = target_position;
		this->velocity = velocity;
		this->type = type;
		this->multiplier = multiplier;
	}

	bool Update(float dt);

	bool HasFinished();

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

	void CreateSpline(int * position, int target_position, int velocity, TypeSpline type, float multiplier = 1.0f);

private:




	std::list<EaseSplineInfo*> easing_splines;


public:



};

#endif 
