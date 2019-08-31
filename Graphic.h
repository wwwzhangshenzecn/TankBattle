#pragma once
#ifndef GRAPHIC_HEADER
#define GRAPHIC_HEADER

#include<conio.h>
#include<time.h>
#include<graphics.h>

#include"Rect.h"

const int MAXSTAR = 100;
const int HEIGHT = 600;
const int WIDTH = 1024;
const int SET_WIDTH = 200;
const int BATTLE_GROUND_x1 = 5;
const int BATTLE_GROUND_y1 = 5;
const int BATTLE_GROUND_x2 = WIDTH-5 - SET_WIDTH;
const int BATTLE_GROUND_y2 = (HEIGHT - BATTLE_GROUND_y1);
const int SCORE_LEFT = 830;
const int SCORE_TOP = 5;

class Graphic {
public:
	static void Create();
	static void Destory();

	static void DrawBattleGround();
	static Rect GetBattleGround();

	static int GetScreenWidth();
	static int GetScreenHeight();
	static void ShowScore();
private:
	static Rect m_rectScreen;
	static Rect m_rectBattleGround;
	static char m_pArray[100];
};


class StarType {
public:
	virtual void Draw(int x, int y, int color) = 0;
	virtual void Remove(int x, int y) = 0;
};

class PointSatr : public StarType {
	void Draw(int x, int y, int color) {
		auto C = RGB(color, color, color);;

		putpixel((int)x, y, C);
		setcolor(C);
		circle(x, y, 1);
	}
	void Remove(int x, int y) {
		putpixel((int)x, y, 0);
		setcolor(0);
		circle(x, y, 1);
	}
};

class RectStar :public StarType {
	void Draw(int x, int y, int color) {
		auto C = RGB(color, color, color);;
		putpixel((int)x, y, C);
		setcolor(C);
		rectangle(x - 1, y - 1, x + 1, y + 1);
	}
	void Remove(int x, int y) {
		putpixel((int)x, y, 0);
		setcolor(0);
		rectangle(x - 1, y - 1, x + 1, y + 1);
	}
};

class XStar : public StarType {
	void Draw(int x, int y, int color) {
		auto C = RGB(color, color, color);;

		settextcolor(C);
		outtextxy(x, y, 'x');
	}
	void Remove(int x, int y) {
		settextcolor(0);
		outtextxy(x, y, 'x');
	}
};

class Star {
public:
	Star() {};
	~Star() {};

	void Init();
	void Init(StarType* pStarType);
	void Move();
protected:
	void NewPos();
private:
	double _x = 0;
	int _y;
	double _step;
	int _color;
	StarType* _pStarType;
};


#endif GRAPHIC_HEADER