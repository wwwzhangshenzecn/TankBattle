#include "EnemyTank.h"


void EnemyTank::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	fillrectangle(m_pos.GetX() - 6, m_pos.GetY() - 6,
		m_pos.GetX()+6, m_pos.GetY()+6);

	fillrectangle(m_pos.GetX() - 11, m_pos.GetY() - 11,
		m_pos.GetX() - 8, m_pos.GetY() - 8);

	fillrectangle(m_pos.GetX() - 11, m_pos.GetY() + 8,
		m_pos.GetX() - 8, m_pos.GetY() + 11);
	fillrectangle(m_pos.GetX() + 8, m_pos.GetY() -11,
		m_pos.GetX() +11, m_pos.GetY() -8);
	fillrectangle(m_pos.GetX() +8, m_pos.GetY() + 8,
		m_pos.GetX() +11, m_pos.GetY() + 11);

	switch (m_dir)
	{
	case UP:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() - 15);
		break;
	case DOWN:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX(), m_pos.GetY() + 15);
		break;
	case LEFT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() - 15, m_pos.GetY());
		break;
	case RIGHT:
		line(m_pos.GetX(), m_pos.GetY(), m_pos.GetX() + 15, m_pos.GetY());
		break;
	default:
		break;
	}
	setcolor(color_save);
	setfillcolor(fill_color_save);
}


void EnemyTank::Move()
{
	if ( m_stepCnt <= 0 ) {
		if(rand() % 100 < 50)
			m_dir = (Dir)(Dir::UP + rand() % 4);
		m_stepCnt = rand() % MAX_STEP + 5;
		m_bNeedShoot = true;
	}
	if (  rand() % 100 < 5) {
		m_bNeedShoot = true;
	}
	m_stepCnt--;
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		if (m_pos.GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
			m_pos.SetY(m_pos.GetY() + m_step), m_dir=Dir::DOWN;
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		if (m_pos.GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
			m_pos.SetY(m_pos.GetY() - m_step),m_dir=Dir::UP;
		break;
	case LEFT:
		m_pos.SetX(m_pos.GetX() - m_step);
		if (m_pos.GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
			m_pos.SetX(m_pos.GetX() + m_step),m_dir=Dir::RIGHT;
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		if (m_pos.GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
			m_pos.SetX(m_pos.GetX() + m_step),m_dir=Dir::LEFT;
		break;
	default:
		break;
	}
	CalculateSphare();
}

void EnemyTank::Shoot(list<Object*>& lstBullet)
{
	Object* pBullet = new Bullet(m_pos, m_dir, m_color);
	lstBullet.push_back(pBullet);
	m_bNeedShoot = false;
}

void EnemyTank::CalculateSphare()
{

	switch (m_dir)
	{
	case UP:
		break;
	case DOWN:
		m_rectSphare.Set(m_pos.GetX() - 11, m_pos.GetY() - 11,
			m_pos.GetX() + 11, m_pos.GetY() + 11);
		break;
	case LEFT:
		m_rectSphare.Set(m_pos.GetX() - 11, m_pos.GetY() - 11,
			m_pos.GetX() + 11, m_pos.GetY() + 11);
		break;
	case RIGHT:
		break;
	default:
		break;
	}
}

void EnemyTank::RandomTank()
{
	m_pos.SetX(rand() % Graphic::GetBattleGround().GetEndPoint().GetX());
	m_pos.SetY(rand() % Graphic::GetBattleGround().GetEndPoint().GetY());
	m_color = WHITE;
	m_dir = (Dir)(Dir::UP + rand() % 4);
	m_step = 2;
	m_stepCnt = rand() % MAX_STEP + 5;
}
