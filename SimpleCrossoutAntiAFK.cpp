#include "head.hpp"

void PressButton(HWND hwnd, int key, int PressOnMSec)
{
    PostMessage(hwnd, WM_KEYDOWN, key, 0);
    Sleep(PressOnMSec);
    PostMessage(hwnd, WM_KEYUP, key, 0);
    Sleep(50);
}

int main()
{   

    std::cout << "Set cursor on prog" << std::endl;
    Sleep(3000);
    POINT P;
    GetCursorPos(&P);
    HWND hwnd = WindowFromPoint(P);
    PressButton(hwnd, KEY_W, 100);
    std::cout << hwnd << std::endl;
    system("pause");
}