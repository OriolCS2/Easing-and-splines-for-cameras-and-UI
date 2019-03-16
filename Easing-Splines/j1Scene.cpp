#include "p2Defs.h"
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

	
	Try(&App->render->camera.x, &App->render->camera.y);
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
	//	*Y += 300 * dt;
		//*cord.second += 300 * dt;
		for (std::list<std::pair<int*, int*>>::iterator item = cord_to_move.begin(); item != cord_to_move.end(); ++item) {
			*item->second += 300 * dt;
		}
	}
		

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) {
		//*Y -= 300 * dt;
		//*cord.second -= 300 * dt;
		for (std::list<std::pair<int*, int*>>::iterator item = cord_to_move.begin(); item != cord_to_move.end(); ++item) {
			*item->second -= 300 * dt;
		}
	}
		

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) {
		//*X += 300 * dt;
		//*cord.first += 300 * dt;
		for (std::list<std::pair<int*, int*>>::iterator item = cord_to_move.begin(); item != cord_to_move.end(); ++item) {
			*item->first += 300 * dt;
		}
	}
		

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) {
		//*X -= 300 * dt;
		//*cord.first -= 300 * dt;
		for (std::list<std::pair<int*, int*>>::iterator item = cord_to_move.begin(); item != cord_to_move.end(); ++item) {
			*item->first -= 300 * dt;
		}
	}
		

	if (App->input->GetKey(SDL_SCANCODE_G) == KEY_REPEAT) {
		App->easing_splines->CreateSpline(&App->render->camera.x, App->render->camera.x + 2000, 2000, EASE);
	}
	App->map->Draw();



	

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

void j1Scene::Try(int *x, int* y)
{
	
	X = x;
	Y = y;

	cord.first = x;
	cord.second = y;

	cord_to_move.push_back(cord);

	
}
