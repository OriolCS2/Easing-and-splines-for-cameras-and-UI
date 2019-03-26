#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include <list>

struct SDL_Texture;
struct SDL_Rect;

class Image;
class CheckBox;
class Label;
class Button;
class UI_Element;


class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

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

	SDL_Rect quad{ -490,300,70,40 };

	
};

#endif // __j1SCENE_H__