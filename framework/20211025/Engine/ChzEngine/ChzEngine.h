#ifndef _CHZENGINE_
#define _CHZENGINE_

#include "../Scene/Scene.h"
#include "../SceneManager/SceneManager.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

class ChzEngine
{
	//singleton
private:
	ChzEngine();
	ChzEngine(const ChzEngine& ref);
	ChzEngine& operator=(const ChzEngine& ref) {};
	~ChzEngine() {};

public:
	static ChzEngine& getInstance()
	{
		static ChzEngine CE;
		return CE;
	}

	//members
private:
	SceneManager& m_SM;
	float m_frameTime;

	//methods
public:
	void init(float frameTime);
	void run();

	/*
private:
	inline void loop() {};
	inline void update() {};
	inline void render() {};
	*/
};

#endif