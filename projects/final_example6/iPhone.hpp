/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description: Declares the iPhone class, which inherits from the
 **              Space class. Represents an iPhone with four network
 **              connections. Overrides the exploit member funtion and
 **              specializes it for this class.
 *********************************************************************/

#ifndef IPHONE_HPP
#define IPHONE_HPP

#include <iostream>
#include "Space.hpp"

class iPhone : public Space {
    public:
        iPhone(const std::string &name);
        ~iPhone();
        virtual void exploit() override;
};

#endif // IPHONE_HPP
