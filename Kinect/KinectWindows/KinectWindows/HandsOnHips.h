#pragma once
#include "gestureInterface.h"
class HandsOnHips :public GestureInterface
{
public:
	HandsOnHips();
	~HandsOnHips();

	bool checkForGesture();
};

