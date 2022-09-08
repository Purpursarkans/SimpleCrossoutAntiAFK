#include "head.hpp"

void PressButton(HWND hwnd, int key, int PressOnMSec)
{
    Beep(100,100);
    PostMessage(hwnd, WM_KEYDOWN, key, 0);
    Sleep(PressOnMSec);
    PostMessage(hwnd, WM_KEYUP, key, 0);
    Sleep(1000);
}

void LClickOnCoord(HWND hwnd, int x, int y)
{
    PostMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(x, y));
    Sleep(50);
    PostMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(x, y));
    Sleep(50);
    std::cout << "message sent..." << std::endl;
}

int main()
{

    MoveWindow(GetConsoleWindow(), MOVE_CONSOLE_X, MOVE_CONSOLE_Y, CONSOLE_WIDTH, CONSOLE_HEIGHT, TRUE);
    SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    std::cout << "Set cursor on prog" << std::endl;
    for(int i = 3; i > 0; i--)
    {
        std::cout << i << " sec sleep" << std::endl;
        Sleep(1000);
    }
    
    POINT P;
    GetCursorPos(&P);
    HWND hwnd = WindowFromPoint(P);
    std::cout << hwnd << std::endl;
    
    for (;;)
    {
        PressButton(hwnd, KEY_W, 500);
        PressButton(hwnd, KEY_SPACE, 500);
        PressButton(hwnd, KEY_S, 500);
        PressButton(hwnd, KEY_SPACE, 500);
        Sleep(3000);
    }

    
    system("pause");
}