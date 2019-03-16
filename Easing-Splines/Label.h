#ifndef __LABEL_H__
#define __LABEL_H__

#include "p2Animation.h"
#include "p2Point.h"
#include "UI_Element.h"
#include "PugiXml\src\pugixml.hpp"

class Label : public UI_Element {
public:

	Label(int x, int y, std::string name, int size, bool CanBeMoved, UI_Element* parent = nullptr);
	virtual ~Label();
	bool Update(float dt);
	void ChangeLabel(std::string label, int size);
public:
	
	std::string name;
	iPoint Distance;
	bool CanBeMoved = false;
};

#endif
