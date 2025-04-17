#include "Window.h"
#include "Windows32API.h"
#include <iostream>
#include <stdexcept>

LRESULT CALLBACK eon::Windows32API::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}
	return NULL;
}

const wchar_t* eon::Windows32API::getWindowName()
{
	return L"EON WINDOW";
}

void eon::Windows32API::mainLoop() {

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

}

eon::Windows32API::Windows32API()
{
	const wchar_t CLASS_NAME[] = L"Eon Engine Window";

	WNDCLASSW wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = CLASS_NAME;

	RegisterClassW(&wc);

	hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		getWindowName(),
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT,
		CW_USEDEFAULT, 
		1280, 
		720, 
		NULL,
		NULL, 
		GetModuleHandle(NULL), 
		NULL);

	if (!hwnd)
	{
		throw std::runtime_error("HWND not initialized");
	}

	ShowWindow(static_cast<HWND>(hwnd), SW_NORMAL);
}

eon::Windows32API::~Windows32API()
{
	DestroyWindow(static_cast<HWND>(hwnd));
}