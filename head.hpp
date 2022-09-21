#ifndef HEAD_HPP
#define HEAD_HPP

const int MOVE_CONSOLE_X = 0;
const int MOVE_CONSOLE_Y = 50;
const int CONSOLE_WIDTH = 255;
const int CONSOLE_HEIGHT = 100;

const int READY_X = 713;
const int READY_Y = 117;

const int TEST_DRIVE_X = 896;
const int TEST_DRIVE_Y = 113;

const int ERROR_OK_X = 680;
const int ERROR_OK_Y = 419;

const int BACK_TO_GARAGE_X = 898;
const int BACK_TO_GARAGE_Y = 681;

#include <iostream>
#include <windows.h>
#include <fstream>

#include "KEYS.HPP"
#include "actions.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "Update.hpp"

#define NameFileVersion "version"
#define UrlVersion "https://raw.githubusercontent.com/Purpursarkans/SimpleCrossoutAntiAFK/main/version"
#define VERSION 1
#define NameProgram "SimpleCrossoutAntiAFK"
#endif