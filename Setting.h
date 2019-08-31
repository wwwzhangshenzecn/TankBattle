#pragma once
#ifndef SETTING_HEADER
#define SETTING_HEADER

using namespace std;
class Setting {
public:
	static void NewGameLevel();
	static void TankDanmaged();

	static int GetLife() {
		return m_nLife;
	}
	static int GetGameLevel() {
		return m_nGameLevel;
	}
	static int GetTankLevel() {
		return m_nTankLevel;
	}
	static int GetTankNum() {
		return m_nTankNum;
	}
	static int GetSumScore() {
		return m_nSumScore;
	}
	static int GetTankScore() {
		return m_nTankScore;
	}
	static int GetTankSum() {
		return m_nTankSum;
	}
	static bool m_bNewLevel;
	
	static void SetLife() { m_nLife++; }
	static void SetGameLevel() { m_nGameLevel++; }
	static void SetTankLevel() { m_nTankLevel++; }
	static void SetTankNum() { m_nTankNum = 10 + (m_nGameLevel - 1) * 5; }
	static void SetTankSum() { m_nTankSum++; };
	static void SetTankScore(int score) { m_nSumScore += score; }
	static void SetSumScore(int score) { m_nSumScore = score; }
private:
	static int m_nLife;//����ֵ
	static int m_nGameLevel;//��Ϸ�ؿ�
	static int m_nTankLevel;//̹�˼���
	static int m_nTankNum; // ��ǰ̹������
	static int m_nSumScore;//�ܷ�
	static int m_nTankScore;//���ٵ÷�
	static int m_nTankSum; // ������̹����
};

#endif SETTING_HEADER