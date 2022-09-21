#include "head.hpp"

const int SOCKET_COUNTER = 100;
int TotalSocket = 0;

#define NameFileVersion "version"
#define UrlVersion "https://raw.githubusercontent.com/Purpursarkans/update/main/version"
#define VERSION 1
#define NameProgram "SimpleCrossoutAntiAFK"

void close() { closesocket(s); }

int main(int argc, char *argv[])
{
    atexit(close);

    sockInit();

    for (int i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
                case 'c':
                    Client();
                    break;
                case 's':
                    Server(SOCKET_COUNTER, TotalSocket);
                    break;
                case 'u':
                    update(argc, argv, NameFileVersion, UrlVersion, VERSION, NameProgram);
                    break;
                default:
                    std::cout << "unknown operation" << std::endl;
            }
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