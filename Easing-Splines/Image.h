#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "p2Animation.h"
#include "p2Point.h"
#include "UI_Element.h"
#include "PugiXml\src\pugixml.hpp"

#define IDLE  336, 398, 328, 103 
#define WIDTH 328
#define HEIGHT 103

class Image : public UI_Element {
public:

	Image(int x, int y, bool WantToBeMoved, UI_Element* parent = nullptr);
	virtual ~Image();
	bool Update(float dt);

private:
	bool WantToBeMoved = false;
	iPoint Distance;
};


#endif
