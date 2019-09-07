/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description: Declares the WebServer class, which inherits from the
 **              Space class. Represents a WebServer with four network
 **              connections. Overrides the exploit member funtion and
 **              specializes it for this class. Is used in the game
 **              as the goal device.
 *********************************************************************/

#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include <iostream>
#include "Space.hpp"

class WebServer : public Space {
    public:
        WebServer(const std::string &name);
        ~WebServer();
        virtual void exploit() override;
};

#endif // WEBSERVER_HPP
