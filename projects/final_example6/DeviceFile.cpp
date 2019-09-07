/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description: Defines the DeviceFile class that represents a generic
 **              file on a device. Possesses a name and text content,
 **              as well as several booleans for use in handling game
 **              flow.
 *********************************************************************/

#include "DeviceFile.hpp"


/*********************************************************************
 ** Description: Default constructor. Assigns initial flase values to
 **              the containsPasswords and read member variables.
 **
 ** Arguments: N/A.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
DeviceFile::DeviceFile() {
    setContainsPasswords(false);
    setRead(false);
}


/*********************************************************************
 ** Description: Constructor. Initializes the primary member variables
 **              with the passed values: name, contents, and whether
 **              or not the file contains passwords.
 **
 ** Arguments: Strings representing the file's name, contents, and a
 **            boolean indicationg whether of not the file contains
 **            passwords.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
DeviceFile::DeviceFile(const std::string &name, const std::string &contents,
                       bool pwds) {
    setName(name);
    setContents(contents);
    setContainsPasswords(pwds);
    setRead(false);
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
DeviceFile::~DeviceFile() {
    // Nothing to do
}


/*********************************************************************
 ** Description: Getter for name member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A string contining the file name.
 *********************************************************************/
std::string DeviceFile::getName() {
    return name;
}


/*********************************************************************
 ** Description: Getter for contents member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A string contining the file contents.
 *********************************************************************/
std::string DeviceFile::getContents() {
    return contents;
}


/*********************************************************************
 ** Description: Getter for containsPasswords member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A boolean indicating whether or not the file contains
 **          passwords.
 *********************************************************************/
bool DeviceFile::getContainsPasswords() {
    return containsPasswords;
}


/*********************************************************************
 ** Description: Getter for read member variable.
 **
 ** Arguments: None.
 **
 ** Preconditions: None.
 **
 ** Returns: A boolean indicating whether or not the file has been
 **          read.
 *********************************************************************/
bool DeviceFile::getRead() {
    return read;
}


/*********************************************************************
 ** Description: Setter for name member variable.
 **
 ** Arguments: A string containing the new name.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void DeviceFile::setName(const std::string &newName) {
    name = newName;
}


/*********************************************************************
 ** Description: Setter for contents member variable.
 **
 ** Arguments: A string containing the new contents.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void DeviceFile::setContents(const std::string &newContents) {
    contents = newContents;
}


/*********************************************************************
 ** Description: Setter for containsPasswords member variable.
 **
 ** Arguments: A boolean indicating whether or not the file contains
 **            passwords.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void DeviceFile::setContainsPasswords(bool flag) {
    containsPasswords = flag;
}


/*********************************************************************
 ** Description: Setter for read member variable.
 **
 ** Arguments: A boolean indicating whether or not the file has been
 **            read.
 **
 ** Preconditions: None.
 **
 ** Returns: Nothing.
 *********************************************************************/
void DeviceFile::setRead(bool flag) {
    read = flag;
}
