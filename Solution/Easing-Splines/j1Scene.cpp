#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "EasingSplines.h"
#include "j1Render.h"
#include "j1Map.h"
#include "j1Scene.h"



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
	
	App->map->Load("Map1.tmx");
	App->render->camera.x -= 300;
	App->render->camera.y -= 200;
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

	/*if (App->input->GetKey(SDL_SCANCODE_G) == KEY_REPEAT) {
		App->easing_splines->CreateSpline(&quad.x, quad.x + 800, 3000, TypeSpline::EASE_IN_CIRC);
	}*/

	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE);
	}
	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE_IN_CIRC);
	}
	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE_IN_OUT_BACK);
	}
	if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE_IN_OUT_EXPO);
	}
	if (App->input->GetKey(SDL_SCANCODE_5) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE_IN_QUAD);
	}
	if (App->input->GetKey(SDL_SCANCODE_6) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE_OUT_CUBIC);
	}
	if (App->input->GetKey(SDL_SCANCODE_7) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE_OUT_ELASTIC);
	}
	if (App->input->GetKey(SDL_SCANCODE_8) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE_OUT_QUART);
	}
	if (App->input->GetKey(SDL_SCANCODE_9) == KEY_DOWN) {
		App->easing_splines->CreateSpline(&App->render->camera.x, -App->render->camera.x - 10450, 6000, TypeSpline::EASE_OUT_QUINT);
	}

	App->map->Draw();

	//App->render->DrawQuad(quad, 255, 0, 255);

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



