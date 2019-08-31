#include<iostream>
#include<list>
#include<string>
#include"Graphic.h"
#include"MainTank.h"
#include"EnemyTank.h"
#include"Shape.h"
#include"Setting.h"
using namespace std;

const int MAX_ENEMY = 10;
int score = 0;
const int ONE_TIME_SCORE = 10;

void CheckCrash(list<Object*> lstBombs,list<EnemyTank*> &lstTanks, list<Object*>& mainTankBullets) {
	/*
		主坦克子弹与敌坦克碰撞检测
	*/
	for (auto itm = mainTankBullets.begin(); itm != mainTankBullets.end();
	itm++) {
		for (auto itl = lstTanks.begin(); itl != lstTanks.end(); itl++) {
			if (Shape::CheckIntersect((*itm)->GetSphare(), (*itl)->GetSphare()))
			{
				lstBombs.push_back(new Bomb((*itm)->GetPos(), BombType::LAGE));
				(*itl)->SetDisapper();
				(*itm)->SetDisapper();
				Setting::TankDanmaged();
			}
		}
	}
}
int i = 0;
void CheckLive(MainTank& mainTank, list<Object*>& lstBullets ) {
	//敌坦克子弹与主坦克碰撞检测
	for (auto iter = lstBullets.begin(); iter != lstBullets.end(); iter++) {
		if (Shape::CheckIntersect( (*iter)->GetSphare(),mainTank.GetSphare() ))
		{
			mainTank.SetDisapper();
			score += ONE_TIME_SCORE;
			break;
		}
	}
}

void DrawNewTank(list<EnemyTank*>& lstTank, MainTank& mainTank) {
	lstTank.clear();
	for (int i = 0; i < Setting::GetTankNum(); i++) {
		lstTank.push_back(new EnemyTank(Setting::GetGameLevel() + 2));
	}
	MainTank m(Setting::GetGameLevel() + 3);
	mainTank = m;
}

void main() {
	srand(time(NULL));
	Graphic::Create();

	settextstyle(20, 0, _T("宋体"));
	Star star[MAXSTAR];
	PointSatr pS;
	RectStar rS;
	XStar xS;
	for (int i = MAXSTAR - 1; i >= 0; i--) {
		int c = rand() % 3;
		switch (c)
		{
		case 0:
			star[i].Init(&pS); break;
		case 1:
			star[i].Init(&rS); break;
		case 2:
			star[i].Init(&xS); break;
		default:
			break;
		}
	}

	MainTank mainTank;
	list<EnemyTank*> lstTank;

	list<Object*> lstBombs;
	lstBombs.clear();

	list<Object*> lstBullet;
	lstBullet.clear();

	list<Object*> lstTankBullet;
	lstTankBullet.clear();

	bool loop = true;
	bool skip = false;
	
	while (loop) {
		settextcolor(RED);
		if (Setting::m_bNewLevel) {
			Setting::m_bNewLevel = false;
			//场上无敌对，游戏升关
			Setting::NewGameLevel();
			DrawNewTank(lstTank, mainTank);
			lstBullet.clear();
			lstTankBullet.clear();
			lstBombs.clear();
		}

		Graphic::ShowScore();

		for (int i = MAXSTAR - 1; i >= 0; i--) {
			star[i].Move();
		}
		Sleep(100);

		CheckLive(mainTank, lstTankBullet);
		CheckCrash(lstBombs, lstTank, lstBullet);


		if (mainTank.IsDisapper()) {
			settextcolor(RED);
			settextstyle(50, 0, _T("宋体"));
			outtextxy(300, 200, "Game Over.");
			Sleep(2000);
			outtextxy(250, 300, "数字键 1 继续/ 2退出");
			bool flag = true;
			while(flag){
				char ch = _getch();
					switch (ch)
					{
					case '1':
						loop = true;
						Graphic::Destory();
						Graphic::Create();
						settextstyle(20, 0, _T("宋体"));
						mainTank=MainTank();
						flag = false;
						Sleep(1000);
						break;
					case '2':
						loop = false;
						flag = false;
						Sleep(2000);
						break;
					default:
						break;
					}
			}
			continue;
		}

		if (kbhit()) {
			int key = getch();
			switch (key)
			{
			case 72:
				mainTank.SetDir(Dir::UP);
				break;
			case 80:
				mainTank.SetDir(Dir::DOWN);
				break;
			case 75:
				mainTank.SetDir(Dir::LEFT);
				break;
			case 77:
				mainTank.SetDir(Dir::RIGHT);
				break;
			case 224: //方向键 高 8位
				break;
			case 27: //ESC
				loop = false;
				break;
			case 32://space shoot
				mainTank.Shoot(lstBullet);
				break;
			case 13://enter
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default:
				break;
			}
		}
		
		if (!skip) {
			cleardevice();
			Graphic::DrawBattleGround();
			mainTank.Move();
			mainTank.Display();

			for (auto iter = lstTank.begin(); iter != lstTank.end(); iter++) {
				if ((*iter)->IsDisapper()) {
					(*iter)->Boom(lstBombs);
					delete *iter;
					iter = lstTank.erase(iter);
					continue;
				}
				(*iter)->Move();
				if ((*iter)->GetNeedShoot()) {
					EnemyTank* p = (EnemyTank*)(*iter);
					p->Shoot(lstTankBullet);
				}
				(*iter)->Display();
			}

			for (auto iter = lstBullet.begin(); iter != lstBullet.end();)
			{
				(*iter)->Move();
				if ((*iter)->IsDisapper()) {
					(*iter)->Boom(lstBombs);
					delete *iter;
					iter = lstBullet.erase(iter);
					
					continue;
				}
				(*iter)->Display();
				iter++;
			}

			for (auto iter = lstTankBullet.begin(); iter != lstTankBullet.end();)
			{
				(*iter)->Move();
				if ((*iter)->IsDisapper()) {

					(*iter)->Boom(lstBombs);
					delete *iter;
					iter = lstBullet.erase(iter);

					continue;
				}
				(*iter)->Display();
				iter++;
			}

			for (auto iter = lstBombs.begin(); iter != lstBombs.end();) {
				(*iter)->Move();
				if ((*iter)->IsDisapper()) {
					delete *iter;
					iter = lstBombs.erase(iter);
					continue;
				}
				(*iter)->Display();
				iter++;
			}
		}
	}



	for (auto iter = lstBombs.begin(); iter != lstBombs.end();
	iter++) {
		delete *iter;
	}
	lstBombs.clear();
	for (auto iter = lstTank.begin(); iter != lstTank.end(); iter++) {
		delete *iter;
	}
	lstTank.clear();
	for (auto iter = lstBullet.begin(); iter != lstBullet.end(); iter++)
		delete * iter;
	lstBullet.clear();

	Graphic::Destory();
}