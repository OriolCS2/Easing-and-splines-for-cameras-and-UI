#ifndef __EASINGSPLINES_H__
#define __EASINGSPLINES_H__

#include "j1Module.h"
#include <list>

struct SDL_Texture;
struct SDL_Rect;


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



public:


};

#endif
