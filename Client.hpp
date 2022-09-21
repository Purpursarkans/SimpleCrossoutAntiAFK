#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "head.hpp"

void Client()
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

    while(true)
    {
        sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

        if(connect(s, (sockaddr *)&sa, sizeof(sa)) != 0)
        {
            std::cout << "Error: failed connect to server.\n";
            Sleep(5000);
            sockInit();
            continue;
        }

        std::cout << "Client connected successful" << std::endl;

        bool infinity = 1;

        while (infinity)
        {
            int SockControl = -1;
            recv(s, (char *)&SockControl, sizeof(int), NULL);
            switch(SockControl)
            {
                case -1:
                    std::cout << "error host" << std::endl;
                    Sleep(5000);
                    infinity = 0;
                    break;
                case 0:
                    exit(0);
                    break;
                case 1:
                    LClickOnCoord(GameHwnd, READY_X, READY_Y);
                    break;
                case 2:
                    LClickOnCoord(GameHwnd, ERROR_OK_X, ERROR_OK_Y);
                    break;
                case 3:
                    LClickOnCoord(GameHwnd, BACK_TO_GARAGE_X, BACK_TO_GARAGE_Y);
                    break;
                case 4:
                    PressButton(GameHwnd, KEY_P, 100);
                    break;
                case 5:
                    PressButton(GameHwnd, KEY_ESC, 100);
                    break;
                default:
                    std::cout << "command error" << std::endl;
            }
        }
    }
}

#endif