#include "Title.h"

Title::Title() {}

void Title::begin()
{
	m_elapsedTime = 0.0f;
	m_progressBarMax = 10;
	m_progressBarValue = 0;
}

void Title::update(float dt)
{
	if (_kbhit())
	{
		_getch();
		m_elapsedTime += dt;
	}
	else
	{
		m_elapsedTime -= 2.0 * dt;
		if (m_elapsedTime < 0.0f) { m_elapsedTime = 0.0f; }
	}
	
	m_progressBarValue = (int)(m_progressBarMax * m_elapsedTime / 5.0f); //hold for 5 sec
	if(m_progressBarValue >= m_progressBarMax) { SceneManager::getInstance().loadScene(1); }
}

void Title::render()
{
	system("cls");
	printf("Hold Any Key to Start\n");
	for (int i = 0; i < m_progressBarMax; i++)
	{
		putchar( (i < m_progressBarValue)? '#' : '-' );
	}
}

void Title::end() {}