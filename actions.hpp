#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "head.hpp"

SOCKET s;
WSADATA ws;
SOCKADDR_IN sa;

void sockInit()
{
    memset(&sa, 0, sizeof(sa));
    WSAStartup(MAKEWORD(2, 2), &ws);
    s = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_port = htons(1111);
}

int ToSec(int sec)
{
    return sec * 1000;
}

int ToMin(int min)
{
    return min * 60000;
}

void PressButton(HWND GameHwnd, int key, int PressOnMSec)
{
    PostMessage(GameHwnd, WM_KEYDOWN, key, 0);
    Sleep(PressOnMSec);
    PostMessage(GameHwnd, WM_KEYUP, key, 0);
    Sleep(ToSec(1));
}

void LClickOnCoord(HWND GameHwnd, int x, int y)
{
    PostMessage(GameHwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(x, y));
    Sleep(50);
    PostMessage(GameHwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(x, y));
    Sleep(50);
}

void AntiAFK(HWND GameHwnd)
{
    while(true)
    {
        PressButton(GameHwnd, KEY_W, 500);
        PressButton(GameHwnd, KEY_SPACE, 500);
        PressButton(GameHwnd, KEY_S, 500);
        PressButton(GameHwnd, KEY_SPACE, 500);
        Sleep(ToSec(5));
    }
}


#endif