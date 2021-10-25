#ifndef _TITLE_
#define _TITLE_

#include "../../../Engine/Scene/Scene.h"
#include "../../../Engine/SceneManager/SceneManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

class Title : public Scene
{
public:
	Title();

public:
	void begin();
	void update(float dt);
	void render();
	void end();

private:
	float m_elapsedTime;
	int m_progressBarValue;
	int m_progressBarMax;
};

#endif