#ifndef ENEMYTANK_HEAD
#define ENEMYTANK_HEAD

#include"Tank.h"
#include"Bullet.h"
const int MAX_STEP = 40;
class EnemyTank : public Tank {
public :
	EnemyTank(int step=4) {
		m_stepCnt = 0;
		m_step = step;
		RandomTank();
		m_bNeedShoot = false;
	}
	~EnemyTank() {}
	void Display();
	void Move();
	bool GetNeedShoot() {
		return m_bNeedShoot;
	}
	Rect GetSphare() {
		return Rect(m_pos.GetX() - 11, m_pos.GetY() - 11,
			m_pos.GetX() + 11, m_pos.GetY() + 11);
	}
	void Shoot(list<Object*>& lstBullet);
protected:
	void CalculateSphare();
	void RandomTank();
	int m_stepCnt;
	int m_bNeedShoot;
};

#endif
