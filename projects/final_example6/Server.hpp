/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description: Declares the Server class, which inherits from the
 **              Space class. Represents a Server with four network
 **              connections. Overrides the exploit member funtion and
 **              specializes it for this class.
 *********************************************************************/

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include "Space.hpp"

class Server : public Space {
    public:
        Server(const std::string &name);
        ~Server();
        virtual void exploit() override;
};

#endif // SERVER_HPP
