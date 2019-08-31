#pragma once
#ifndef BULLET_HEADER
#define BULLET_HEADER

#include"Object.h"
#include"Bomb.h"
class Bullet : public Object {
public:
	Bullet();
	Bullet(Point pos, Dir dir, COLORREF color);
	~Bullet() ;

	void Display();

	void Move();
	bool IsDisapper() {
		return m_bDisapper;
	}
	void Boom(list<Object*>& lstBombs);
	
	Point GetPos() { return m_pos; }

	Rect GetSphare() {
		return Rect(m_pos.GetX() - 4, m_pos.GetY() - 4,
			m_pos.GetX() + 4, m_pos.GetY() + 4);
	}
protected:
	void CalculateSphare();
};

#endif BULLET_HEADER