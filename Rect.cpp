#include "Rect.h"

void Rect::Set(const Point & pS, const Point & pE)
{
	m_startPoint=pS;
	m_endPoint=pE;
}

void Rect::Set(int x1, int y1, int x2, int y2)
{
	m_startPoint.Set(x1, y1);
	m_endPoint.Set(x2, y2);
}

void Rect::SetStartPoint(const Point & p)
{
	m_startPoint = p;
}

void Rect::SetEndPoint(const Point & p)
{
	m_endPoint = p;
}

Point Rect::GetTRPoint() 
{
	
	return Point(m_endPoint.GetX(), m_startPoint.GetY());
}

Point Rect::GetBLPoint()
{

	return Point(m_startPoint.GetX(), m_endPoint.GetY());
}

Point Rect::GetStartPoint() const
{
	return m_startPoint;
}

Point Rect::GetEndPoint() const
{
	return m_endPoint;
}

int Rect::GetWidth()
{
	return m_endPoint.GetX() - m_startPoint.GetX();
}

int Rect::GetHeight()
{
	return m_endPoint.GetY()-m_startPoint.GetY();
}

void Rect::Check()
{
	if (m_startPoint.GetX() > m_endPoint.GetX() ||
		m_startPoint.GetY() > m_endPoint.GetY()) {
		Point p = m_startPoint;
		m_startPoint = m_endPoint;
		m_endPoint = p;
	}
}
