#include "UI_Element.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Input.h"
#include "j1Fonts.h"
#include "UI_Manager.h"

#include "j1Window.h"

UI_Element::UI_Element()
{
}

UI_Element::UI_Element(int x, int y)  
{
	pugi::xml_document	config_file;
	pugi::xml_node		config;


	config = App->LoadConfig(config_file, "config.xml");
	UI_node = config.child("UI");



	Scree_pos.x = x + -App->render->camera.x;
	Scree_pos.y = y + -App->render->camera.y;
	


}

UI_Element::~UI_Element()
{
}

bool UI_Element::Update(float dt)
{



	return true;
}

bool UI_Element::CleanUp()
{

	return true;
}

void UI_Element::Draw(float dt, SDL_Texture* texture)
{

	App->render->Blit(texture, Scree_pos.x, Scree_pos.y, &(png_pos));

	if (App->ui_manager->debug_draw) {
		App->render->DrawQuad({ Scree_pos.x,Scree_pos.y,width,height }, 255, 0, 0, 255, false);
	}
	

}

void UI_Element::SetSpritesData(SDL_Rect Idle, SDL_Rect Hover, SDL_Rect Pressed)
{
	if (type != IMAGE) {
		NoPressedNoMouseOn = Idle;
		MouseOn = Hover;
		this->Pressed = Pressed;
		width = Hover.w;
		height = Hover.h;
	}
	else {
		png_pos = Idle;
		width = Idle.w;
		height = Idle.h;
	}

}




