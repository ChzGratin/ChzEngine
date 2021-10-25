#include "SceneManager.h"

SceneManager::SceneManager() : m_isSceneChanging(false), m_nextSceneID(0) {}
SceneManager::SceneManager(const SceneManager& ref) : m_isSceneChanging(false), m_nextSceneID(0) {}

void SceneManager::insertScene(unsigned int sceneID, Scene* pScene) { m_scenes.insert(pair<unsigned int, Scene*>(sceneID, pScene)); }
void SceneManager::wrapper_insertScenes() { insertScenes(); }
void SceneManager::loadScene(unsigned int sceneID) { m_isSceneChanging = true; m_nextSceneID = sceneID; }

bool SceneManager::getIsSceneChanging() { return m_isSceneChanging; }
unsigned int SceneManager::getNextSceneID() { return m_nextSceneID; }
Scene* SceneManager::getScene(unsigned int sceneID) { return m_scenes.at(sceneID); }

void SceneManager::setIsSceneChanging(bool isSceneChanging) { m_isSceneChanging = isSceneChanging; }