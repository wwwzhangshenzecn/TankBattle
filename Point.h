#ifndef POINT_HEADER
#define POINT_HEADER

class Point {
public:
	Point(int x = 0, int y = 0) :m_x(x), m_y(y) {}
	Point(const Point& p) {
		this->m_x = p.m_x;
		this->m_y = p.m_y;
	}

	~Point() {}

	Point& operator = (const Point & p) {
		this->m_x = p.m_x;
		this->m_y = p.m_y;
		return *this;
	}

	int GetX();
	int GetY();
	void Set(int x, int y);
	void SetX(int x);
	void SetY(int y);

private:
	int m_x;
	int m_y;
};

#endif POINT_HEADER