/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/20/2017
 **
 ** Description: Defines the Space class. Used as an abstract base
 **              class representing a generic space with four
 **              potential connections to adjoining spaces. In this
 **              game, the space is used to represent a device on a
 **              network and the connections to other spaces are taken
 **              to be network connections.
 *********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include <string>
#include "DeviceFile.hpp"


class Space {
    private:
        std::string name;
        std::string description;
        int difficulty;
        bool exploited;
        Space *top;
        Space *right;
        Space *left;
        Space *bottom;
        std::vector<DeviceFile> files;

    public:
        Space();
        virtual ~Space();

        Space * getTop();
        Space * getRight();
        Space * getLeft();
        Space * getBottom();

        std::string getDescription();
        std::string getName();
        int getDifficulty();
        bool getExploited();
        std::vector<DeviceFile> getFiles();
        DeviceFile takeFile(size_t index);
        
        void setTop(Space *newTop);
        void setRight(Space *newRight);
        void setLeft(Space *newLeft);
        void setBottom(Space *newBottom);

        void setDescription(const std::string &desc);
        void setName(const std::string &newName);
        void setDifficulty(int newDiff);
        void setExploited(bool flag);
        void addFile(DeviceFile newFile);
        void setFileAsRead(int index);

        // Pure virtual
        virtual void exploit() = 0;
};

#endif  // SPACE_HPP
