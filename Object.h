#pragma once
#ifndef OBJECT_HEADER
#define OBJECT_HEADER
#include<list>
#include"Graphic.h"
using namespace std;
enum Dir { UP, DOWN, LEFT, RIGHT };
enum BombType { LAGE, SMALL ,GOD};

class Object {

public:
	Object() {}
	virtual void Display() = 0;
	virtual void Move() = 0;
	virtual void Boom(list<Object*>& lstBombs) = 0;
	virtual bool IsDisapper() = 0;
	Point GetPos() { return m_pos; }
	virtual Rect GetSphare() = 0;
	void SetDisapper() { m_bDisapper = true; }
protected:
	virtual void CalculateSphare() = 0;

	Point m_pos;
	Rect m_rectSphare;
	COLORREF m_color;

	Dir m_dir;
	bool m_bDisapper;
	int m_step;
};

#endif OBJECT_HEADER