#include "head.hpp"

const int SOCKET_COUNTER = 100;
int TotalSocket = 0;

void close() { closesocket(s); }

int main(int argc, char *argv[])
{
    atexit(close);

    sockInit();

    std::cout << "argc " << argc << std::endl;

    for (int i = 0; i < argc; i++)
    {
        std::string temp = argv[i];
        std::cout << temp << std::endl;
        system("pause");
        if (temp == "-up" || temp == "-u" || temp == "-uc" || temp == "-d" || temp == "-dc")
        {
            update(argc, argv, NameFileVersion, UrlVersion, VERSION, NameProgram);
        }
        else if (temp == "-cu")
        {
            update(argc, argv, NameFileVersion, UrlVersion, VERSION, NameProgram, temp);
        }
        else if (temp == "-s")
        {
            Server(SOCKET_COUNTER, TotalSocket);
        }
        else if (temp == "-c")
        {
            Client();
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