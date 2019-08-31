#ifndef BOMB_HEADER
#define BOMB_HEADER
	
#include"Object.h"

class Bomb :public Object {
public:
	Bomb();
	Bomb(Point pos, BombType type);
	~Bomb();

	Rect GetSphare() {
		return m_rectSphare;
	}

	void Display();
	void Move();
	void Boom(list<Object*>& lstBombs);

	bool IsDisapper();
protected:
	void CalculateSphare();
	BombType m_type;
	int m_timer;
};

#endif // !BOMB_HEADER
