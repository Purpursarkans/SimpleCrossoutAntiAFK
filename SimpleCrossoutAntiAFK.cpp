#include <iostream>
#include <windows.h>

int main()
{   
    POINT P;
    GetCursorPos(&P);
    HWND hwnd = WindowFromPoint(P);
    // PostMessage(hwnd, WM_KEYDOWN, VK_C, 0);
    PostMessage(hwnd, WM_KEYDOWN, 8, 0);
    std::cout << hwnd << std::endl;
    system("pause");
}