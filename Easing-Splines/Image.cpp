#include "Image.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "p2Log.h"
#include "UI_Manager.h"
#include "j1Input.h"

Image::Image(int x, int y) : UI_Element(x, y)
{
	width = WIDTH;
	height = HEIGHT;
	png_pos = {IDLE};

}

Image::~Image()
{
}


