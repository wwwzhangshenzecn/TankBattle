#include "Shape.h"

bool Shape::CheckPointInRect(Point & point, Rect & rect)
{
	if (point.GetX() < rect.GetStartPoint().GetX() ||
		point.GetX() > rect.GetEndPoint().GetX() ||
		point.GetY() < rect.GetStartPoint().GetY() ||
		point.GetY() > rect.GetEndPoint().GetY())

		return false;
	else {
		return true;
	}
}

bool Shape::CheckIntersect(Rect & rectA, Rect & rectB)
{
	if (CheckPointInRect(rectA.GetBLPoint(), rectB) ||
		CheckPointInRect(rectA.GetEndPoint(), rectB) ||
		CheckPointInRect(rectA.GetStartPoint(), rectB) ||
		CheckPointInRect(rectA.GetTRPoint(), rectB))
		return true;
	else
		return false;
}
