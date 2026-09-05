#include "window.h"
#include <iostream>

MainWindow::MainWindow()
    : hwnd_(nullptr),
      is_running_(false),
      window_width_(1280),
      window_height_(800)
{
}

MainWindow::~MainWindow()
{
    if (hwnd_)
    {
        DestroyWindow(hwnd_);
    }
}

bool MainWindow::Create(const wchar_t* title, int width, int height)
{
    window_width_ = width;
    window_height_ = height;

    // Register window class
    WNDCLASSW wnd_class = {};
    wnd_class.lpfnWndProc = WindowProc;
    wnd_class.lpszClassName = L"AndroidEmulatorWindow";
    wnd_class.hInstance = GetModuleHandle(nullptr);
    wnd_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wnd_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if (!RegisterClassW(&wnd_class))
    {
        std::cerr << "Failed to register window class" << std::endl;
        return false;
    }

    // Create window
    hwnd_ = CreateWindowW(
        L"AndroidEmulatorWindow",
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        nullptr, nullptr,
        GetModuleHandle(nullptr),
        this
    );

    if (!hwnd_)
    {
        std::cerr << "Failed to create window" << std::endl;
        return false;
    }

    std::cout << "Main window created: " << width << "x" << height << std::endl;
    return true;
}

void MainWindow::Show()
{
    if (hwnd_)
    {
        ShowWindow(hwnd_, SW_SHOW);
        is_running_ = true;
    }
}

void MainWindow::Hide()
{
    if (hwnd_)
    {
        ShowWindow(hwnd_, SW_HIDE);
    }
}

void MainWindow::RunMessageLoop()
{
    MSG msg = {};
    while (GetMessageW(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
}

void MainWindow::Close()
{
    if (hwnd_)
    {
        PostMessage(hwnd_, WM_CLOSE, 0, 0);
    }
}

LRESULT CALLBACK MainWindow::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    MainWindow* pThis = nullptr;

    if (msg == WM_CREATE)
    {
        CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lparam);
        pThis = reinterpret_cast<MainWindow*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
    }
    else
    {
        pThis = reinterpret_cast<MainWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    }

    if (pThis)
    {
        return pThis->HandleMessage(msg, wparam, lparam);
    }

    return DefWindowProcW(hwnd, msg, wparam, lparam);
}

LRESULT MainWindow::HandleMessage(UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_CLOSE:
        is_running_ = false;
        PostQuitMessage(0);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd_, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd_, &ps);
        return 0;
    }

    default:
        return DefWindowProcW(hwnd_, msg, wparam, lparam);
    }
}
