#pragma once
#include "Window.h"
#include <Windows.h>

namespace eon
{
	class Windows32API : public Window
	{
	public:
		static LRESULT CALLBACK WindowProc(HWND hwnd,
			UINT uMsg,
			WPARAM wParam,
			LPARAM lParam);
		const wchar_t* getWindowName() override;
		void mainLoop();
		Windows32API();
		~Windows32API();
	private:
		void* hwnd;
	};
}