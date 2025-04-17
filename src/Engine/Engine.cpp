#include <iostream>
#include <Windows.h>

#ifdef _DEBUG
int main()
#else
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#endif
{
#ifdef _DEBUG
	HINSTANCE hInstance = GetModuleHandle(NULL);
	HINSTANCE hPrevInstance = NULL;
	PWSTR pCmdLine = GetCommandLineW();
	int nCmdShow = SW_NORMAL;
#endif

	// Create Windows

	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, DefWindowProc,
		0, 0, hInstance, NULL, NULL, NULL, NULL, "EngineClass", NULL };
	RegisterClassEx(&wc);
	HWND hwnd = CreateWindowEx(0, "EngineClass", "Engine Window", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	// Main message loop
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	// Cleanup
	DestroyWindow(hwnd);

	return 0;
}