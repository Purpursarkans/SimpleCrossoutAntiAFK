#include <iostream>
#include <windows.h>

#define TAB 0x09

void PressButton(HWND hwnd, int key)
{
    PostMessage(hwnd, WM_KEYDOWN, key, 0);
    Sleep(34);
    PostMessage(hwnd, WM_KEYUP, key, 0);
    Sleep(50);
}

int main()
{   
    POINT P;
    GetCursorPos(&P);
    HWND hwnd = WindowFromPoint(P);
    PressButton(hwnd, TAB);
    std::cout << hwnd << std::endl;
    system("pause");
}