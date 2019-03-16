#include "UI_Manager.h"
#include "Button.h"
#include "j1Input.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "p2Log.h"
#include "Label.h"
#include "CheckBox.h"
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
		if ((*item) != nullptr && (*item)->parent == nullptr) {
			(*item)->Draw(dt, atlas);
			std::list < UI_Element*>::iterator item2 = (*item)->Son.begin();
			for (; item2 != (*item)->Son.end(); ++item2) {
				(*item2)->Draw(dt, atlas);
				std::list<UI_Element*>::iterator item3 = (*item2)->Son.begin();
				for (; item3 != (*item2)->Son.end(); ++item3) {
					(*item3)->Draw(dt, atlas);
				}
			}
		}
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

Button * UI_Manager::CreateButton(int x, int y, UI_Element* parent, std::string name, int size)
{
	Button* ret = nullptr;
	
	ret = new Button(x, y, parent, name, size);
	ret->type = BUTTON;

	if (ret != nullptr)
		elements.push_back(ret);

	return ret;
}
CheckBox * UI_Manager::CreateCheckBox(int x, int y, UI_Element* parent)
{
	CheckBox* ret = nullptr;

	ret = new CheckBox(x, y, parent);
	ret->type = CHECKBOX;

	if (ret != nullptr)
		elements.push_back(ret);

	return ret;
}


Image * UI_Manager::CreateImage(int x, int y, bool WantToBeMoved, UI_Element * parent)
{
	Image* ret = nullptr;

	ret = new Image(x, y, WantToBeMoved, parent);
	ret->type = IMAGE;

	if (ret != nullptr)
		elements.push_back(ret);

	return ret;
}

Label * UI_Manager::CreateLabel(int x, int y, std::string name, int size, bool CanBeMoved, UI_Element* parent)
{
	Label* ret = nullptr;

	ret = new Label(x, y, name, size, CanBeMoved, parent);
	ret->type = LABEL;

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



