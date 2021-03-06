#include "p2Log.h"
#include "EasingSplines.h"

EasingSplines::EasingSplines() : j1Module()
{
	name.assign("easingsplines");
	
}

// Destructor
EasingSplines::~EasingSplines()
{

}

// Called each loop iteration
bool EasingSplines::Update(float dt)
{
	std::list<EaseSplineInfo*>::iterator item = easing_splines.begin();

	for (; item != easing_splines.end(); ++item) {
		if (*item != nullptr) {
			if (!(*item)->Update(dt)) {
				delete(*item);
				(*item) = nullptr;
			}
		}
	}

	easing_splines.remove(nullptr);

	return true;
}

// Called before quitting
bool EasingSplines::CleanUp()
{
	LOG("Freeing scene");

	std::list<EaseSplineInfo*>::iterator item = easing_splines.begin();

	for (; item != easing_splines.end(); ++item) {
		if (*item != nullptr) {
			delete(*item);
			(*item) = nullptr;
		}
	}

	easing_splines.clear();

	return true;
}

void EasingSplines::CreateSpline(int * position, const int &target_position, const float &time_to_travel, const TypeSpline &type)
{

	EaseSplineInfo* info = new EaseSplineInfo(position, target_position, time_to_travel, type);

	if (info != nullptr)
		easing_splines.push_back(info);
	else
		LOG("Could not create the Spline...");
}




bool EaseSplineInfo::Update(float dt)
{
	bool ret = true;

	// TODO 2: Calculate the time that has passed since the spline started. Save this value in a float. 1 line
	
	
	// TODO 3: Think how can we know if a spline has finished or not using the time calculated before. 
	// If the splines has finished, Update must end with a false in order to delete it, look line 21. 

	// TODO 4: If the spline has not finished, make a switch with the spline type and call its type function. Look what this function returns! 
	// Make this for 1 case just to test, choose the spline you want.

	return ret;
}

int EaseFunctions::EaseOutQuint(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	return distance_to_travel * ((time_passed = time_passed / time_to_travel - 1)*time_passed*time_passed*time_passed*time_passed + 1) + initial_position;;
}

int EaseFunctions::Ease(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	return distance_to_travel * (time_passed / time_to_travel) + initial_position;
}

int EaseFunctions::EaseInOutBack(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	int pos = 0;
	float s = 1.70158f;
	if ((time_passed /= time_to_travel / 2) < 1) {
		pos = distance_to_travel / 2 * (time_passed*time_passed*(((s *= (1.525f)) + 1)*time_passed - s)) + initial_position;
	}
	else {
		float postFix = time_passed -= 2;
		pos = distance_to_travel / 2 * ((postFix)*time_passed*(((s *= (1.525f)) + 1)*time_passed + s) + 2) + initial_position;
	}
	return pos;
}

int EaseFunctions::EaseOutQuart(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	return -distance_to_travel * ((time_passed = time_passed / time_to_travel - 1)*time_passed*time_passed*time_passed - 1) + initial_position;
}

int EaseFunctions::EaseInQuad(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	return distance_to_travel * (time_passed /= time_to_travel)*time_passed + initial_position;
}

int EaseFunctions::EaseInOutExpo(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	int pos = 0;

    if ((time_passed /= time_to_travel / 2) < 1) {
		pos = distance_to_travel / 2 * pow(2, 10 * (time_passed - 1)) + initial_position;
	}
	else {
		pos = distance_to_travel / 2 * (-pow(2, -10 * --time_passed) + 2) + initial_position;
	}
	return pos;
}

int EaseFunctions::EaseOutElastic(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	int pos = 0;

	if ((time_passed /= time_to_travel) == 1) {
		pos = initial_position + distance_to_travel;
	}
	else {
		pos = (distance_to_travel*pow(2, -10 * time_passed) * sin((time_passed*time_to_travel - ((time_to_travel * 0.3)/4))*(2 * 3.14) / (time_to_travel * 0.3)) + distance_to_travel + initial_position);
	}
	return pos;
}

int EaseFunctions::EaseOutCubic(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	return distance_to_travel * ((time_passed = time_passed / time_to_travel - 1)*time_passed*time_passed + 1) + initial_position;
}

int EaseFunctions::EaseInCirc(float &time_passed, const int &initial_position, const int &distance_to_travel, const float &time_to_travel)
{
	return -distance_to_travel * (sqrt(1 - (time_passed /= time_to_travel)*time_passed) - 1) + initial_position;
}
