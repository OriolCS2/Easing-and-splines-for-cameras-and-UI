#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "EasingSplines.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"
#include <string>
#include "UI_Manager.h"
#include "Image.h"



j1Scene::j1Scene() : j1Module()
{
	name.assign("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	//std::string map("iso_walk.tmx");
	
	App->map->Load("iso_walk.tmx");
	App->render->camera.x += 500;
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{

	// debug pathfing ------------------


	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT) {
		App->render->camera.y += 300 * dt;
	}
		

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) {
		App->render->camera.y -= 300 * dt;
	}
		

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) {
		App->render->camera.x += 300 * dt;
	}
		

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) {
		App->render->camera.x -= 300 * dt;
	}
		


	if (App->input->GetKey(SDL_SCANCODE_G) == KEY_REPEAT) {
		App->easing_splines->CreateSpline(&quad.x, quad.x + 1000, 3000, TypeSpline::EASE_OUT_QUART);
	}





	App->map->Draw();

	App->render->DrawQuad(quad, 255, 0, 255);

	
	

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}



