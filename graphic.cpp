#include<iostream>
#include<string>
#include"Graphic.h"
#include"Setting.h"

using namespace std;
Rect Graphic::m_rectScreen;
Rect Graphic::m_rectBattleGround;
char Graphic::m_pArray[100];

void Graphic::ShowScore() {
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(SCORE_LEFT, SCORE_TOP,
		SCORE_LEFT + 200, SCORE_TOP + 50);

	RECT r = { SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40 };
	string msg = "第 " + to_string(Setting::GetGameLevel()) + " 关";
	//wsprintf((LPSTR)m_pArray, _T("第 %d 关"), Setting::GetGameLevel());
	drawtext(msg.c_str(),&r, DT_CENTER);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("分 数 ： %d"), Setting::GetSumScore());
	drawtext((LPSTR)m_pArray, &r,  DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("级 别 ： %d"), Setting::GetTankLevel());
	drawtext((LPSTR)m_pArray, &r,  DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("生 命 ： %d"), Setting::GetLife());
	drawtext((LPSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("敌人数 ： %d"), Setting::GetTankNum());
	drawtext((LPSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	line(SCORE_LEFT, r.bottom, WIDTH - 5, r.bottom);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("共击毁敌人数 ： %d"), Setting::GetTankSum());
	drawtext((LPSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}



void Graphic::
Create() {
	m_rectScreen.Set(0, 0, WIDTH, HEIGHT);
	initgraph(WIDTH, HEIGHT);
	setbkcolor(DARKGRAY);

	m_rectBattleGround.Set(BATTLE_GROUND_x1, BATTLE_GROUND_y1,
		BATTLE_GROUND_x2, BATTLE_GROUND_y2 );
}


void Graphic::Destory() {
	closegraph();
}

void Graphic::DrawBattleGround() {
	rectangle(m_rectBattleGround.GetStartPoint().GetX(),
		m_rectBattleGround.GetStartPoint().GetY(),
		m_rectBattleGround.GetEndPoint().GetX(),
		m_rectBattleGround.GetEndPoint().GetY() );
}

int Graphic::GetScreenHeight() {
	return HEIGHT;
}
int Graphic::GetScreenWidth() {
	return WIDTH;
}

Rect Graphic::GetBattleGround() {
	return m_rectBattleGround;
}