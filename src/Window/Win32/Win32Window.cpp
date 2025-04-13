#define UNICODE
#include <Window/Win32/Window.h>
#include <Windows.h>
#include <stdexcept>
#include <d3d12.h>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }

    return 0;
}

eon::Window::Window()
{

    WNDCLASSEX wc{};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpszClassName = L"EONWindow";
    wc.lpfnWndProc = &WindowProcedure;
    auto windowClassId = RegisterClassEx(&wc);

    if (!windowClassId)
        throw std::runtime_error("RegisterClassEx failed.");

    RECT rc{0, 0, 1280, 720};

    AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

    m_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"Eon Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

    if (!m_handle)
        throw std::runtime_error("CreateWindowEx failed.");

    ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);
}

eon::Window::~Window()
{
    DestroyWindow(static_cast<HWND>(m_handle));
}