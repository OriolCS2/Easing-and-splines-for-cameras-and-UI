#ifndef __j1FONTS_H__
#define __j1FONTS_H__

#include "j1Module.h"
#include "SDL\include\SDL_pixels.h"

#define DEFAULT_FONT "fonts/Sunday-Afternoon.ttf"
#define DEFAULT_FONT_SIZE 50

struct SDL_Texture;
struct _TTF_Font;

class j1Fonts : public j1Module
{
public:

	j1Fonts();

	// Destructor
	virtual ~j1Fonts();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before quitting
	bool CleanUp();

	// Load Font
	_TTF_Font* const Load(const char* path, int size = 12);



	// Create a surface from text
	SDL_Texture* Print(const char* text, _TTF_Font* font, SDL_Color color = {0, 0, 0, 255});

	bool CalcSize(const char* text, int& width, int& height, _TTF_Font* font = NULL) const;

public:
	const char* path = nullptr;
	std::list<_TTF_Font*>	fonts;
	_TTF_Font*			default;
	_TTF_Font*			InitialMenu = nullptr;
	_TTF_Font*			Time = nullptr;
	_TTF_Font*			PlayerUI = nullptr;
};


#endif // __j1FONTS_H__