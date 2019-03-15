#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "EasingSplines.h"
#include <string>

EasingSplines::EasingSplines() : j1Module()
{
	name.assign("easingsplines");
}

// Destructor
EasingSplines::~EasingSplines()
{}

// Called before render is available
bool EasingSplines::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool EasingSplines::Start()
{

	return true;
}

// Called each loop iteration
bool EasingSplines::PreUpdate()
{



	return true;
}

// Called each loop iteration
bool EasingSplines::Update(float dt)
{







	return true;
}

// Called each loop iteration
bool EasingSplines::PostUpdate()
{
	bool ret = true;

	return ret;
}

// Called before quitting
bool EasingSplines::CleanUp()
{
	LOG("Freeing scene");

	return true;
}


