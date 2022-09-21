#include "head.hpp"

const int SOCKET_COUNTER = 100;
int TotalSocket = 0;

void close() { closesocket(s); }

int main(int argc, char *argv[])
{
    atexit(close);

    sockInit();

    for (int i = 0; i < argc; i++)
    {
        std::string temp = argv[i];
        if (temp == "-u")
        {
            update(argc, argv, NameFileVersion, UrlVersion, VERSION, NameProgram);
        }
        if (temp == "-s")
        {
            Server(SOCKET_COUNTER, TotalSocket);
        }
        if (temp == "-c")
        {
            Client();
        }
        if (temp == "-uc")
        {
            update(argc, argv, NameFileVersion, UrlVersion, VERSION, NameProgram, temp);
        }
    }

    std::cout << "select work mode:" << std::endl;

    char c;
    std::cout << "s - server\nc - client" << std::endl;
    std::cout << ">> ";
    std::cin >> c;

    if (c == 'c')
    {
        Client();
    }
    if (c == 's')
    {
        Server(SOCKET_COUNTER, TotalSocket);
    }
}