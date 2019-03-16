#ifndef __CHECKBOX_H__
#define __CHECKBOX_H__

#include "p2Animation.h"
#include "p2Point.h"
#include "UI_Element.h"
#include "PugiXml\src\pugixml.hpp"

class CheckBox : public UI_Element {
public:

	CheckBox(int x, int y, UI_Element* parent = nullptr);
	virtual ~CheckBox();
	bool Update(float dt);
};

#endif
