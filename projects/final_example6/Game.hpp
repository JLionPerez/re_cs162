/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/20/2017
 **
 ** Description: The core class for running the finalproject program.
 **              Handles the execution of a single game where the
 **              object is to navigate a computer network with the
 **              ultimate goal of bringing down the University of
 **              Oregon web server. Players must collect various files
 **              to accomplish this goal. The game ends when the player
 **              runs out of 'hops' (representing the ability to
 **              perform actions) or successfully completes the mission.
 *********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <thread>   // std::this_thread::sleep_for
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "menu.hpp"
#include "Space.hpp"
#include "iPhone.hpp"
#include "DesktopPC.hpp"
#include "Server.hpp"
#include "WebServer.hpp"
#include "DeviceFile.hpp"


class Game {
    private:
        Space *currentLocation;
        Space *previousLocation;
        int hopsLeft;
        size_t inventoryLimit;
        bool playing;
        bool wonGame;
        std::vector<Space *> networkMap;
        std::vector<DeviceFile> inventory;

        // Menu and utility functions
        void decrementHop();
        void initializeNetworkConnections();
        void setNetworkDeviceDescriptions();
        void setNetworkDeviceDifficulty();
        void addFilesToDevices();
        void printInventory();
        void exploitCurrentDevice();
        void stealFile();
        void printFile();
        void move();
        void returnToPrevious();
        void printMap();
        void clearScreen();
        void hackingAnimation();
        char generateRandomChar();
        void transmissionAnimation();
        void fileTransferAnimation();

    public:
        Game();
        ~Game();
        void play();
};

#endif  // GAME_HPP
