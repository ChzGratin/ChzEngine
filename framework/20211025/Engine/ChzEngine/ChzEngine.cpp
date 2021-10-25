#include "ChzEngine.h"

ChzEngine::ChzEngine()                     : m_SM(SceneManager::getInstance()), m_frameTime(1.0f/20) {}
ChzEngine::ChzEngine(const ChzEngine& ref) : m_SM(SceneManager::getInstance()), m_frameTime(1.0f/20) {}

void ChzEngine::init(float frameTime)
{
	m_SM.wrapper_insertScenes();
	m_frameTime = frameTime;
}

void ChzEngine::run()
{
	unsigned int sceneID; Scene* pScene = nullptr;
	system_clock::time_point t0, t1;
	float dt, acc;

	t0 = system_clock::now();
	acc = 0.0f;
	while (1)
	{
		if ( m_SM.getIsSceneChanging() )
		{
			if (pScene) { pScene->end(); }

			sceneID = m_SM.getNextSceneID();
			pScene  = m_SM.getScene(sceneID);
			m_SM.setIsSceneChanging(false);

			pScene->begin();
			t0 = system_clock::now();
			acc = 0.0f;
		}

		t1 = system_clock::now();
		dt = duration_cast<microseconds>(t1 - t0).count() / 1000000.0f + acc;

		if (dt < m_frameTime) { continue; }
		else
		{
			t0 = system_clock::now();
			acc = 0.0f;

			while (dt >= m_frameTime)
			{
				pScene->update(m_frameTime);
				dt -= m_frameTime;
			}
			acc += dt;

			pScene->render();
		}
	}
}

/*
void ChzEngine::loop() {}
void ChzEngine::update() {}
void ChzEngine::render() {}
*/