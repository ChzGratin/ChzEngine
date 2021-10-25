#ifndef _SCENEMANAGER_
#define _SCENEMANAGER_

#include "../Scene/Scene.h"

#include <map>

using namespace std;

extern void insertScenes(); //insertScenes.cpp

class SceneManager
{
	//singleton
private:
	SceneManager();
	SceneManager(const SceneManager& ref);
	SceneManager& operator=(const SceneManager& ref) {};
	~SceneManager() {};

public:
	static SceneManager& getInstance()
	{
		static SceneManager SM;
		return SM;
	};

	//members
private:
	map<unsigned int, Scene*> m_scenes;
	bool m_isSceneChanging;
	unsigned int m_nextSceneID;

	//methods
public:
	void insertScene(unsigned int sceneID, Scene* pScene);
	void wrapper_insertScenes();
	void loadScene(unsigned int sceneID);

	//get
	bool         getIsSceneChanging();
	unsigned int getNextSceneID();
	Scene*       getScene(unsigned int sceneID);

	//set
	void setIsSceneChanging(bool isSceneChanging);
};

#endif