/*********************************************************************
 ** Program name: finalproject
 ** 
 ** Author: Caleb Schmidt
 ** 
 ** Date: 11/20/2017
 ** 
 ** Description: Declares the various menu helper functions defined in
 **              menu.cpp. Used to gather and validate input from the
 **              user in a flexible and reuseable manner.
 *********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>


// Place the menu helper functions in their own namespace
// to prevent clashes and to make usage obvious and explicit
namespace menu {

    // Prompt the user to run the program or quit
    bool runOrQuit(const std::string &prompt);

    // Includes default arguments for min and max to allow
    // simplified calls when any valid int is acceptable
    int getValidInt(const std::string &prompt,
                    const std::string &errorMessage,
                    int min=std::numeric_limits<int>::lowest(),
                    int max=std::numeric_limits<int>::max());

    // Get a Boolean representing a response to a yes or no question
    bool getYesOrNo(const std::string &promt);

    // Get a random integer within the specified range, inclusive
    int getRandomIntInRange(int min, int max);

    // Given a list of options, prompt until one is entered
    char getCharFromOptions(const std::string &prompt,
                            const std::string &errorMessage,
                            const std::vector<char> &validOptions);

    // Prompt the user until a valid input filename is given and can be opened
    void openInFile(const std::string &prompt,
                    const std::string &errorMessage,
                    std::ifstream &inFile);

    // Prompt the user until a valid output filename is given and can be opened
    void openOutFile(const std::string &prompt,
                     const std::string &errorMessage,
                     std::ofstream &outFile);

    // Prompt the user to enter an arbitrary string
    std::string getString(const std::string &prompt);
}

#endif // MENU_HPP
