#ifndef _SCENE_
#define _SCENE_

class Scene
{
public:
	virtual ~Scene() {}; //because of "new T:Scene" in insertScenes.cpp

public:
	virtual void begin();
	virtual void update(float dt);
	virtual void render();
	virtual void end();
};

#endif