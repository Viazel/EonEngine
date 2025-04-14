#include <Windows.h>
#include "Window/Win32/Window.h"

int main()
{

    auto m_display = new eon::Window();

    MSG msg{};

    bool is_running = true;

    while (is_running)
    {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                is_running = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    delete m_display;

    return 0;
}