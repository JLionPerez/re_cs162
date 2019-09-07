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

#include "Space.hpp"


/*********************************************************************
 ** Description: Default constructor. Initializes all connections to
 **              other spaces to nullptr. Also sets the state to not
 **              exploited.
 **
 ** Arguments: N/A.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
Space::Space() {
    setTop(nullptr);
    setBottom(nullptr);
    setLeft(nullptr);
    setRight(nullptr);
    setExploited(false);
}


/*********************************************************************
 ** Description: Destructor.
 **
 ** Arguments: N/A.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
Space::~Space() {
    // Nothing to do
}


/*********************************************************************
 ** Description: Getter for top member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A pointer to a space.
 *********************************************************************/
Space * Space::getTop() {
    return top;
}


/*********************************************************************
 ** Description: Getter for right member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A pointer to a space.
 *********************************************************************/
Space * Space::getRight() {
    return right;
}


/*********************************************************************
 ** Description: Getter for left member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A pointer to a space.
 *********************************************************************/
Space * Space::getLeft() {
    return left;
}


/*********************************************************************
 ** Description: Getter for bottom member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A pointer to a space.
 *********************************************************************/
Space * Space::getBottom() {
    return bottom;
}


/*********************************************************************
 ** Description: Getter for description member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A string representing the description of the space.
 *********************************************************************/
std::string Space::getDescription() {
    return description;
}


/*********************************************************************
 ** Description: Getter for name member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A string representing the name of the space.
 *********************************************************************/
std::string Space::getName() {
    return name;
}


/*********************************************************************
 ** Description: Getter for difficulty member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: An integer representing the difficulty to exploit the space.
 *********************************************************************/
int Space::getDifficulty() {
    return difficulty;
}

/*********************************************************************
 ** Description: Getter for exploited member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A boolean indicating whether or not the device has been
 **          exploited.
 *********************************************************************/
bool Space::getExploited() {
    return exploited;
}


/*********************************************************************
 ** Description: Getter for files member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A vector contining the files in the space.
 *********************************************************************/
std::vector<DeviceFile> Space::getFiles() {
    return files;
}


/*********************************************************************
 ** Description: Takes the index of a file, and transfers that file to
 **              the caller, destroying the local copy.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A DeviceFile object.
 *********************************************************************/
DeviceFile Space::takeFile(size_t index) {
    DeviceFile temp;
    if (index < files.size()) {
        temp = files[index];
        files.erase(files.begin() + index);
    }

    return temp;
}


/*********************************************************************
 ** Description: Setter for top member variable.
 **
 ** Arguments: Returns: A pointer to a space.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Space::setTop(Space *newTop) {
    top = newTop;
}


/*********************************************************************
 ** Description: Setter for right member variable.
 **
 ** Arguments: Returns: A pointer to a space.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Space::setRight(Space *newRight) {
    right = newRight;
}


/*********************************************************************
 ** Description: Setter for left member variable.
 **
 ** Arguments: Returns: A pointer to a space.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Space::setLeft(Space *newLeft) {
    left = newLeft;
}


/*********************************************************************
 ** Description: Setter for bottom member variable.
 **
 ** Arguments: Returns: A pointer to a space.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void Space::setBottom(Space *newBottom) {
    bottom = newBottom;
}


/*********************************************************************
 ** Description: Setter for description member variable.
 **
 ** Arguments: A string representing the description of the space.
 **
 ** Preconditions: None.
 **
 ** Returns: None.
 *********************************************************************/
void Space::setDescription(const std::string &desc) {
    description = desc;
}


/*********************************************************************
 ** Description: Setter for name member variable.
 **
 ** Arguments: A string representing the name of the space.
 **
 ** Preconditions: None.
 **
 ** Returns: None.
 *********************************************************************/
void Space::setName(const std::string &newName) {
    name = newName;
}


/*********************************************************************
 ** Description: Setter for difficulty member variable.
 **
 ** Arguments: An integer representing the difficulty to exploit the space.
 **
 ** Preconditions: None.
 **
 ** Returns: None.
 *********************************************************************/
void Space::setDifficulty(int newDiff) {
    difficulty = newDiff;
}


/*********************************************************************
 ** Description: Setter for exploited member variable.
 **
 ** Arguments: A boolean indicating whether or not the device has been
 **            exploited.
 **
 ** Preconditions: None.
 **
 ** Returns: None.
 *********************************************************************/
void Space::setExploited(bool flag) {
    exploited = flag;
}


/*********************************************************************
 ** Description: Adds a file to the device.
 **
 ** Arguments: A DeviceFile to add to the device.
 **
 ** Preconditions: None.
 **
 ** Returns: None.
 *********************************************************************/
void Space::addFile(DeviceFile newFile) {
    files.push_back(newFile);
}


/*********************************************************************
 ** Description: Sets the read variable of the indicated file to true.
 **
 ** Arguments: The index of the file to mark as read.
 **
 ** Preconditions: None.
 **
 ** Returns: None.
 *********************************************************************/
void Space::setFileAsRead(int index) {
    files[index].setRead(true);
}
