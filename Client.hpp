#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "head.hpp"

void Client(SOCKET &s, SOCKADDR_IN &sa)
{
    HWND GameHwnd = NULL;
    while (GameHwnd == NULL)
    {
        std::cout << "Search TargemWindow(Crossout)" << std::endl;
        GameHwnd = FindWindowA("TargemWindow", NULL);
        if (GameHwnd == NULL)
        {
            Sleep(ToSec(1));
        }
    }

    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)AntiAFK, (LPVOID)(GameHwnd), NULL, NULL);

    sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    if(connect(s, (sockaddr *)&sa, sizeof(sa)) != 0)
    {
        std::cout << "Error: failed connect to server.\n";
        exit(1);
    }

    std::cout << "Client connected successful" << std::endl;

    while(true)
    {
        int SockControl = 0;
        recv(s, (char *)&SockControl, sizeof(int), NULL);
        switch(SockControl)
        {
            case 0:
                std::cout << "error host" << std::endl;
                system("pause");
                exit(1);
                break;
            case 1:
                LClickOnCoord(GameHwnd, READY_X, READY_Y);
                break;
            case 2:
                LClickOnCoord(GameHwnd, BACK_TO_GARAGE_OK_X, BACK_TO_GARAGE_OK_X);
                break;
            case 3:
                PressButton(GameHwnd, KEY_P, 100);
                break;
            case 4:
                PressButton(GameHwnd, KEY_ESC, 100);
                break;
            default:
                std::cout << "command error" << std::endl;
        }
    }
}

#endif