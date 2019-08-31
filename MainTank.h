#ifndef MAINTANK_H
#define MAINTANK_H

#include"Tank.h"

class MainTank : public Tank {
public:

	~MainTank() {}

	MainTank(int step = 2) {
		m_pos.Set(300, 300);

		CalculateSphare();

		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = step;
	}

	// ÐÐÊ»·½Ïò
	void SetDir(Dir dir);
	
	void Display();
	void Move();
	void Shoot(list<Object*>& lstBullet);
	void SetDisapper() { m_bDisapper = true; }
	Rect GetSphare() {
		return Rect(m_pos.GetX() - 11, m_pos.GetY() - 11,
			m_pos.GetX() + 11, m_pos.GetY() + 11);
	}
protected:
	void DrawTankBody();
	void CalculateSphare();
};


#endif MAINTANK_H