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

	void Try(int *x, int* y);

	void CreateMenuToMove();

public:
	int* X = nullptr;
	int* Y = nullptr;

	std::pair<int*, int*> cord;

	std::list<std::pair<int*, int*>> cord_to_move;

	SDL_Rect rect{ -500,200,100,100 };

	//MENU
	Button* buttonGOBACKSETTINGS = nullptr;
	Image* imageSETTINGS = nullptr;
	CheckBox* checkboxFPS = nullptr;
	Label* labelFPS = nullptr;
	SDL_Texture* Settings = nullptr;
	Label* labelMUSICVOLUME = nullptr;
	Label* labelSETTINGS = nullptr;
	Label* labelVOLUMEFX = nullptr;
	Label* labelGODMODE = nullptr;
	CheckBox* checkboxGODMODE = nullptr;
	Label* labelGENERALSOUND = nullptr;
	CheckBox* checkboxSOUND = nullptr;
	Label* labelSOUND = nullptr;
	int x = 170;
	int y = 950;


	
};

#endif // __j1SCENE_H__