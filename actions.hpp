#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "head.hpp"

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
    PressButton(GameHwnd, KEY_W, 500);
    PressButton(GameHwnd, KEY_SPACE, 500);
    PressButton(GameHwnd, KEY_S, 500);
    PressButton(GameHwnd, KEY_SPACE, 500);
    Sleep(ToSec(5));
}

#endif