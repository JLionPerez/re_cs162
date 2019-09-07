/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description: Declares the DeviceFile class that represents a generic
 **              file on a device. Possesses a name and text content,
 **              as well as several booleans for use in handling game
 **              flow.
 *********************************************************************/

#ifndef DEVICEFILE_HPP
#define DEVICEFILE_HPP

#include <string>


class DeviceFile {
    private:
        std::string name;
        std::string contents;
        bool containsPasswords;
        bool read;

    public:
        DeviceFile();
        DeviceFile(const std::string &name,
                   const std::string &contents,
                   bool pwds);
        ~DeviceFile();

        std::string getName();
        std::string getContents();
        bool getContainsPasswords();
        bool getRead();

        void setName(const std::string &newName);
        void setContents(const std::string &newContents);
        void setContainsPasswords(bool flag);
        void setRead(bool flag);
};

#endif  // DEVICEFILE_HPP
