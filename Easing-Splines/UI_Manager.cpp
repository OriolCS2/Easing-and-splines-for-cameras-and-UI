#include "UI_Manager.h"
#include "j1Input.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "p2Log.h"
#include "Label.h"
#include "Image.h"

UI_Manager::UI_Manager()
{

	name.assign("UI");

}

UI_Manager::~UI_Manager()
{
}

bool UI_Manager::Awake(pugi::xml_node & config)
{
	sprite = config.child("sprite").text().as_string();

	return true;
}

bool UI_Manager::Start()
{
	atlas = App->tex->Load(sprite.data());

	return true;
}

bool UI_Manager::Update(float dt)
{

	if (App->input->GetKey(SDL_SCANCODE_F8) == KEY_DOWN) {
		debug_draw = !debug_draw;
	}

	std::list<UI_Element*>::iterator item = elements.begin();

	for (; item != elements.end(); ++item) {
		if ((*item) != nullptr)
			(*item)->Update(dt);
	}
	
	item = elements.begin();

	for (; item != elements.end(); ++item) {
		if ((*item) != nullptr)
			(*item)->Draw(dt,atlas);
	}

	

	return true;
}

bool UI_Manager::CleanUp()
{
	
	
	std::list<UI_Element*>::iterator item = elements.begin();

	for (; item != elements.end(); ++item) {
		if ((*item) != nullptr) {
			delete(*item);
			(*item) = nullptr;
			elements.erase(item);
		}
			
	}


	elements.clear();

	return true;
}

void UI_Manager::Draw(float dt, SDL_Texture* texture)
{
}

bool UI_Manager::Load(pugi::xml_node &)
{
	return true;
}

bool UI_Manager::Save(pugi::xml_node &) const
{
	return true;
}

Image * UI_Manager::CreateImage(int x, int y)
{
	Image* ret = nullptr;

	ret = new Image(x, y);
	ret->type = IMAGE;

	if (ret != nullptr)
		elements.push_back(ret);

	return ret;
}

void UI_Manager::DeleteAllUI()
{
	std::list<UI_Element*>::iterator item = elements.begin();

	for (; item != elements.end(); ++item) {
		if ((*item) != nullptr) {
			delete(*item);
			(*item) = nullptr;
			elements.erase(item);
		}

	}

	elements.clear();
}



