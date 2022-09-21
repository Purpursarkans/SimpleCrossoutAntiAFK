#include "head.hpp"

const int SOCKET_COUNTER = 100;
int TotalSocket = 0;

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

void close() { closesocket(s); }

int main()
{
    //MoveWindow(GetConsoleWindow(), MOVE_CONSOLE_X, MOVE_CONSOLE_Y, CONSOLE_WIDTH, CONSOLE_HEIGHT, TRUE);
    //SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    atexit(close);

    sockInit();

    std::cout << "select work mode:" << std::endl;

    char c;
    std::cout << "s - server\nc - client" << std::endl;
    std::cout << ">> ";
    std::cin >> c;

    if (c == 'c')
    {
        Client(s, sa);
    }
    if (c == 's')
    {
        Server(s, sa, SOCKET_COUNTER, TotalSocket);
    }
}