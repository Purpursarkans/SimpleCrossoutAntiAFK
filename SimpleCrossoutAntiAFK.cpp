#include "head.hpp"

const int SOCKET_COUNTER = 100;
int TotalSocket = 0;

void close() { closesocket(s); }

int main(int argc, char *argv[])
{
    std::ofstream rFile;
    rFile.open("version");
    rFile << TIME << std::endl;
    rFile << "https://github.com/Purpursarkans/SimpleCrossoutAntiAFK/blob/main/SimpleCrossoutAntiAFK.exe?raw=true" << std::endl;
    rFile.close();
    
    atexit(close);

    sockInit();

    for (int i = 0; i < argc; i++)
    {
        std::string temp = argv[i];
        if (temp == "-up" || temp == "-u" || temp == "-uc" || temp == "-d" || temp == "-d2" || temp == "-dc" || temp == "-dc2")
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