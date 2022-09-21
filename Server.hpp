#ifndef SERVER_HPP
#define SERVER_HPP

#include "head.hpp"

SOCKET *ClientSockets;
int TotalSocket2;

void CommandSend()
{
    int SockControl = 0;
    
    while(true)
    {
        if (TotalSocket2 > 0)
        {   
            system("cls");
            std::cout << "connect succesful" << std::endl;
            while (true)
            {
                system("cls");
                std::cout << "Enter command" << std::endl
                          << "1 - Ready" << std::endl
                          << "2 - click ok(return on garage)" << std::endl
                          << "3 - Press P" << std::endl
                          << "4 - Press ESC" << std::endl
                          << std::endl;
                std::cin >> SockControl;
                for (int i = 0; i < TotalSocket2; i++)
                {
                    send(ClientSockets[i], (char *)&SockControl, sizeof(int), 0);
                }
            }
        }
        else
        {
            Sleep(1000);
            system("cls");
            std::cout << "waiting connect" << std::endl;
        }
    }
}
void Server(SOCKET &s, SOCKADDR_IN &sa, int SOCKET_COUNTERS, int TotalSockets)
{
    ClientSockets = new SOCKET[SOCKET_COUNTERS];

    bind(s, (sockaddr *)&sa, sizeof(sa));

    listen(s, 100);

    SOCKET ClientSocket;
    SOCKADDR_IN ClientAddr;
    int ClientAddrSize = sizeof(ClientAddr);
    std::cout << "Server started succesful" << std::endl;

    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CommandSend, NULL, NULL, NULL);

    for (int i = 0; i < SOCKET_COUNTERS; i++)
    {
        ClientSocket = accept(s, (sockaddr *)&ClientAddr, &ClientAddrSize);
        if (ClientSocket == 0)
        {
            std::cout << "Error #2\n";
            exit(1);
        }
        else
        {
            std::cout << std:: endl << "connection ok" << std::endl;
            ClientSockets[i] = ClientSocket;
            TotalSockets++;
            TotalSocket2 = TotalSockets;
        }
    }
    delete[] ClientSockets;
}

#endif