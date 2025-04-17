#include <iostream>
#include "Window/Windows32API.h"

int main()
{
	eon::Windows32API mainWindow;
	
	mainWindow.mainLoop();

	return 0;
}