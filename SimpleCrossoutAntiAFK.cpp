#include "head.hpp"

void PressButton(HWND hwnd, int key, int PressOnMSec)
{
    PostMessage(hwnd, WM_KEYDOWN, key, 0);
    Sleep(PressOnMSec);
    PostMessage(hwnd, WM_KEYUP, key, 0);
    Sleep(50);
}

void antiAfk(HWND hwnd, int key, int PressOnMSec, int sleep)
{
    for(;;)
    {
        PressButton(hwnd, key, PressOnMSec);
        Sleep(sleep);
    }
}

int main()
{   

    std::cout << "Set cursor on prog" << std::endl;
    Sleep(3000);
    POINT P;
    GetCursorPos(&P);
    HWND hwnd = WindowFromPoint(P);
    antiAfk(hwnd, KEY_W, 300, 3000);
    std::cout << hwnd << std::endl;
    system("pause");
}