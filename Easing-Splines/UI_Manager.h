#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include "j1Module.h"
#include "p2Animation.h"
#include <list>

class Button;
class UI_Element;
class Image;
class CheckBox;
struct SDL_Texture;

class UI_Manager : public j1Module
{
public:

	UI_Manager();
	~UI_Manager();

	bool Awake(pugi::xml_node& config);

	bool Start();

	bool Update(float dt);

	bool CleanUp();
	void Draw(float dt, SDL_Texture* texture);
	bool Load(pugi::xml_node&);

	bool Save(pugi::xml_node&) const;

	Image* CreateImage(int x, int y);
	
	void DeleteAllUI();


private:

	std::list<UI_Element*> elements;
	SDL_Texture* atlas = nullptr;
	std::string sprite;

public:
	bool debug_draw = false;
};

#endif
