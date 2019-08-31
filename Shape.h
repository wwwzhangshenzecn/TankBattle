#pragma once
#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include"Rect.h"

class Shape {
public:
	static bool CheckPointInRect(Point& point, Rect& rect);
	static bool CheckIntersect(Rect& rectA, Rect& rectB);
};

#endif SHAPE_HEADER