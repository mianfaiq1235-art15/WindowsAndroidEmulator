// Windows UI component header
#pragma once

#include <windows.h>
#include <string>

class MainWindow
{
public:
    MainWindow();
    ~MainWindow();

    bool Create(const wchar_t* title, int width, int height);
    void Show();
    void Hide();
    void RunMessageLoop();
    bool IsRunning() const { return is_running_; }
    void Close();

    HWND GetHandle() const { return hwnd_; }

private:
    HWND hwnd_;
    bool is_running_;
    int window_width_;
    int window_height_;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
    LRESULT HandleMessage(UINT msg, WPARAM wparam, LPARAM lparam);
};
