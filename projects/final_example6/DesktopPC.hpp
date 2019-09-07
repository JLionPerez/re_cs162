/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description: Declares the DesktopPC class, which inherits from the
 **              Space class. Represents a Desktop PC with four network
 **              connections. Overrides the exploit member funtion and
 **              specializes it for this class.
 *********************************************************************/

#ifndef DESKTOPPC_HPP
#define DESKTOPPC_HPP

#include <iostream>
#include "Space.hpp"

class DesktopPC : public Space {
    public:
        DesktopPC(const std::string &name);
        ~DesktopPC();
        virtual void exploit() override;
};

#endif // DESKTOPPC_HPP
