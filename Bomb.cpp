#include "Bomb.h"

Bomb::Bomb()
{
	this->m_bDisapper = false;
	this->m_color = YELLOW;
	this->m_dir = UP;
}

Bomb::Bomb(Point pos, BombType type):Bomb()
{
	this->m_pos = pos;
	this->m_type = type;
	switch (m_type)
	{
	case GOD:
		m_timer = 25; break;
	case LAGE:
		m_timer = 8;
		break;
	case SMALL:
		m_timer = 4;
		break;
	default:
		break;
	}
}

Bomb::~Bomb()
{
}

void Bomb::Display()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);

	fillcircle(m_pos.GetX(), m_pos.GetY(), 8 - m_timer);
	
	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Bomb::Move()
{
	m_timer -= 2;
	if (m_timer < 0)
		m_bDisapper = true;
}

void Bomb::Boom(list<Object*>& lstBombs)
{
	lstBombs.push_back(new Bomb(m_pos, (BombType)(rand() % 2)));
}

bool Bomb::IsDisapper()
{
	return m_bDisapper;
}

void Bomb::CalculateSphare()
{
}
