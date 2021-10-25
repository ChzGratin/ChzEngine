#include "../ChzEngine/ChzEngine.h"

int main()
{
	ChzEngine& CE = ChzEngine::getInstance();
	CE.init(1.0f/5); //5 FPS
	CE.run();

	return 0;
}