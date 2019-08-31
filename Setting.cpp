#include "Setting.h"

bool Setting::m_bNewLevel = true;
int Setting::m_nGameLevel = 0;
int Setting::m_nTankLevel = 1;
int Setting::m_nTankNum = 5;
int Setting::m_nSumScore = 0;
int Setting::m_nTankScore = 0;
int Setting::m_nTankSum = 0;
int Setting::m_nLife = 3;

void Setting::NewGameLevel()
{
	m_nGameLevel++;
	m_nTankNum = 5 + 5 * (m_nGameLevel - 1);
	m_nTankScore += 5;
}

void Setting::TankDanmaged()
{
	// 场面上坦克减一， 分数增长
	m_nTankNum--;
	m_nSumScore += m_nTankScore;
	m_nTankLevel = m_nSumScore / 150 + 1;
	m_nTankSum++;
	if (m_nTankNum <= 0) {// 没有敌人，新的游戏关卡需要重新设定
		m_bNewLevel = true;
	}
}

