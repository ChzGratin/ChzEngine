#include "NewWorld.h"

void NewWorld::begin() {}

void NewWorld::update(float dt)
{
	if (_kbhit())
	{
		_getch();
		SceneManager::getInstance().loadScene(0);
	}
}

void NewWorld::render()
{
	system("cls");
	printf("Hello, world!\n");
	printf("Press any key to continue...");
}

void NewWorld::end() {}