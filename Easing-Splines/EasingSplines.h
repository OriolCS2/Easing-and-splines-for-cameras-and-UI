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


/*struct EaseSplineInfo {

	int * position;
	int target_position;
	int velocity;
	TypeSpline type;
	float multiplier;

	bool Update();

	/*EaseSplineInfo(int * position, int target_position, int velocity, TypeSpline type, float multiplier = 1.0f) {
		this->position = position;
		this->target_position = target_position;
		this->velocity = velocity;
		this->type = type;
		this->multiplier = multiplier;
	}

};*/

struct EaseSplineInfo
{
	int * position;
	int target_position;
	int velocity;
	TypeSpline type;
	float multiplier;

	bool Update();
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

	void CreateSpline(int * position, int target_position, int velocity, TypeSpline type, float multiplier = 1.0f);

private:




	std::list<EaseSplineInfo*> easing_splines;


public:



};

#endif 
