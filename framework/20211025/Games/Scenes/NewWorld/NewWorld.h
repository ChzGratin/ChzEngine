#ifndef _NEWWORLD_
#define _NEWWORLD_

#include "../../../Engine/Scene/Scene.h"
#include "../../../Engine/SceneManager/SceneManager.h"
#include <stdio.h>
#include <conio.h>

class NewWorld : public Scene
{
public:
	void begin();
	void update(float dt);
	void render();
	void end();
};

#endif