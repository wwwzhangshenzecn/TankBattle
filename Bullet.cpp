#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Point pos, Dir dir, COLORREF color)
{
	m_pos = pos;
	m_dir = dir;
	m_color = color;

	m_step = 20;
	m_bDisapper = false;

	CalculateSphare();
}

Bullet::~Bullet()
{
}

void Bullet::Display()
{
	COLORREF fill_color_save = getfillcolor()
		;
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	fillcircle(m_pos.GetX() - 1, m_pos.GetY() - 1, 4);
	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Bullet::Move()
{
	switch (m_dir)
	{
	case UP:
		m_pos.SetY(m_pos.GetY() - m_step);
		CalculateSphare();
		if (m_rectSphare.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
			m_bDisapper = true,
			m_pos.SetY(Graphic::GetBattleGround().GetStartPoint().GetY()+2);
		break;
	case DOWN:
		m_pos.SetY(m_pos.GetY() + m_step);
		CalculateSphare();
		if (m_rectSphare.GetStartPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
			m_bDisapper = true, m_pos.SetY(Graphic::GetBattleGround().GetEndPoint().GetY() -2);
		break;
	case LEFT:

		m_pos.SetX(m_pos.GetX() - m_step);
		CalculateSphare();
		if (m_rectSphare.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
			m_bDisapper = true, m_pos.SetX(Graphic::GetBattleGround().GetStartPoint().GetX()+2);
		break;
	case RIGHT:
		m_pos.SetX(m_pos.GetX() + m_step);
		CalculateSphare();
		if (m_rectSphare.GetStartPoint().GetX()> Graphic::GetBattleGround().GetEndPoint().GetX())
			m_bDisapper = true, m_pos.SetX(Graphic::GetBattleGround().GetEndPoint().GetX()-2);
		break;
	default:
		break;
	}
}

void Bullet::Boom(list<Object*>& lstBombs)
{
	lstBombs.push_back(new Bomb(m_pos, SMALL));
}

void Bullet::CalculateSphare()
{
	m_rectSphare.Set(m_pos.GetX() - 2,
		m_pos.GetY() - 2, m_pos.GetX() + 2,
		m_pos.GetY() + 2);
}
