#include "../../Engine/ChzEngine/ChzEngine.h"
#include "../Scenes/Title/Title.h"
#include "../Scenes/NewWorld/NewWorld.h"

//e.g.)
//#include "MyScene.h"

void insertScenes()
{
	SceneManager& SM = SceneManager::getInstance();

	//e.g.)
	//MyScene* pMS = new MyScene;
	//SM.insertScene(0, pMS);
	//SM.loadScene(0);

	Title* title = new Title;
	NewWorld* newworld = new NewWorld;

	SM.insertScene(0, title);
	SM.insertScene(1, newworld);

	SM.loadScene(0);
}