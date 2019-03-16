#include "Label.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "p2Log.h"
#include "UI_Manager.h"
#include "j1Input.h"
#include "j1Fonts.h"
#include "SDL_TTF\include\SDL_ttf.h"


Label::Label(int x, int y, std::string name, int size, bool CanBeMoved, UI_Element* parent) : UI_Element (x,y, parent)
{
	this->CanBeMoved = CanBeMoved;
	this->name = name;
	if (!CanBeMoved) {
		Distance.x = Scree_pos.x - (-App->render->camera.x);
		Distance.y = Scree_pos.y - (-App->render->camera.y);
		if (App->fonts->PlayerUI == nullptr) {
			App->fonts->PlayerUI = App->fonts->Load(App->fonts->path, size);
		}
		tex = App->fonts->Print(name.data(), App->fonts->PlayerUI);
		App->fonts->CalcSize(name.data(), width, height, App->fonts->PlayerUI);
	}
	else {

		//TTF_CloseFont(App->fonts->InitialMenu);
		App->fonts->InitialMenu = App->fonts->Load(App->fonts->path, size);
		tex = App->fonts->Print(name.data(), App->fonts->InitialMenu);
		App->fonts->CalcSize(name.data(), width, height, App->fonts->InitialMenu);
	}

}

Label::~Label()
{
	App->tex->UnLoad(tex);
}

bool Label::Update(float dt)
{
	if (!CanBeMoved) {
		Scree_pos.x = (-App->render->camera.x) + Distance.x;
		Scree_pos.y = (-App->render->camera.y) + Distance.y;
	}

	return true;
}

void Label::ChangeLabel(std::string label, int size)
{
	if (App->fonts->Time == nullptr)
		App->fonts->Time = App->fonts->Load(App->fonts->path, size);
	App->tex->UnLoad(tex);
	tex = App->fonts->Print(label.data(), App->fonts->Time);
	App->fonts->CalcSize(label.data(), width, height, App->fonts->Time);
}
