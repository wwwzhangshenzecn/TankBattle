#ifndef __TANK_H__
#define __TANK_H__

#include "Object.h"
#include "Bomb.h"
#include <list>

using namespace std;

class Tank : public Object
{
public:
	Tank()
	{
		m_pos.Set(300, 300);

		this->CalculateSphere();

		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 4;

		m_bDisapper = false;
	}

	~Tank() {}

	void Display()
	{
		// Display
	}

	void Move()
	{
		// Move
	}
	Rect GetSphare() {
		return m_rectSphare;
	}
	void Boom(list<Object*>& lstBombs) {
		lstBombs.push_back(new Bomb(m_pos, (BombType)(rand() % 2)));
	};

	// Éä»÷
	void Shoot(list<Object*>& lstBullets)
	{
		// Shoot
	}

	bool IsDisapper()
	{
		return m_bDisapper;
	}

protected:
	void CalculateSphere()
	{
		// Calculate Sphere
	}
};

#endif