#ifndef UPDATE_HPP
#define UPDATE_HPP

#include "head.hpp"

void update(int argc, char *argv[], std::string NameFileVersion, std::string sVersionUrl, int VERSION, std::string exeName, std::string StartKey = "")
{
    static std::string exeNameCopy = exeName + "2";

    for (int i = 1; i < argc; i++)
    {
        std::string temp = argv[i];
        if (temp == "-u")
        {
            std::string remove_ = exeName + ".exe";
            while (remove(remove_.c_str())) { }

            std::string copy_ = "copy " + exeNameCopy + ".exe " + exeName + ".exe /Y";

            system(copy_.c_str());

            std::string start = "start cmd /C \"" + exeNameCopy + ".exe -d\"";
            system(start.c_str());
            exit(0);
        }
        else if (temp == "-uc")
        {
            std::string remove_ = exeName + ".exe";
            while (remove(remove_.c_str())) { }
            std::string copy_ = "copy " + exeNameCopy + ".exe " + exeName + ".exe /Y";

            system(copy_.c_str());

            std::string start = "start cmd /C \"" + exeNameCopy + ".exe -dc\"";
            system(start.c_str());
            exit(0);
        }
        else if (temp == "-d")
        {
            std::string start = "start cmd /C \"" + exeName + ".exe -d2\"";

            system(start.c_str());
            exit(0);
        }
        else if (temp == "-d2")
        {
            std::string remove_ = exeNameCopy + ".exe";
            while (remove(remove_.c_str())) { }
            std::string start = "start " + exeName + ".exe";

            system(start.c_str());
            exit(0);
        }
        else if (temp == "-dc")
        {
            std::string start = "start cmd /C \"" + exeName + ".exe -dc2\"";
            system(start.c_str());
            exit(0);
        }
        else if (temp == "-dc2")
        {
            std::string remove_ = exeNameCopy + ".exe";
            while (remove(remove_.c_str())) { }

            std::string start = "start cmd /C \"" + exeName + ".exe -c\"";
            system(start.c_str());
            exit(0);
        }
    }

    std::string downloadVersion = "curl -o " + NameFileVersion + " -L " + sVersionUrl;
    system(downloadVersion.c_str());

    std::ifstream rFile(NameFileVersion);
    std::string versionS;
    std::string downloadFileUrl;
    std::getline(rFile, versionS);
    std::getline(rFile, downloadFileUrl);
    int versionI = std::stoi(versionS);

    rFile.close();

    while (remove(NameFileVersion.c_str())) { }

    std::cout << "Last version: " << versionI << std::endl;
    std::cout << "Total version: " << VERSION << std::endl;

    if (versionI > VERSION)
    {
        std::cout << "Need update" << std::endl;
        std::cout << "Start update" << std::endl;

        std::string curl;

        if (StartKey == "")
        {
            std::cout << "Start key = 0" << std::endl;
            curl = "curl -o " + exeNameCopy + ".exe " + "-L " + downloadFileUrl + " && start cmd /C \"" + exeNameCopy + ".exe -u\"";
        }
        else if (StartKey == "-cu")
        {
            std::cout << "Start key = -cu" << std::endl;
            curl = "curl -o " + exeNameCopy + ".exe " + "-L " + downloadFileUrl + " && start cmd /C \"" + exeNameCopy + ".exe -uc\"";
        }

        system(curl.c_str());
        exit(0);
    }
    else if (versionI == VERSION)
    {
        std::cout << "All update" << std::endl;
        Sleep(5000);
        system("cls");
    }
    else if (versionI < VERSION)
    {
        std::cout << "You have a newer version" << std::endl;
        Sleep(5000);
        system("cls");
    }
    else
    {
        std::cout << "I dont know what happens" << std::endl;
        Sleep(5000);
        system("cls");
    }
    if (StartKey == "-cu")
    {
        system("start cmd /C\"SimpleCrossoutAntiAFK -c\"");
        exit(0);
    }
}

#endif