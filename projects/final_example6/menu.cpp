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

#include "menu.hpp"


using std::cin;
using std::cout;
using std::endl;


// A namespace to encompass all menu helper functions
namespace menu {

    /*********************************************************************
     ** Description: Prompts the user with the passed prompt string and a 
     **              quit option. Continues looping until the user enters
     **              a valid yes or no response, displaying an error
     **              message and re-displaying the menu options after
     **              each failed entry.
     ** 
     ** Arguments: A string used to customize the initial menu option.
     ** 
     ** Preconditions: None.
     ** 
     ** Returns: A boolean value representing whether or not the user
     **          wishes to run the program.
     *********************************************************************/
    bool runOrQuit(const std::string &prompt) {

        // Holds the final result
        int value;

        // Holds the answer to the question of whether to run the program
        bool runProgram;

        // Flag to indicate whether we have been successful yet or not
        bool validInput = false;

        do {
            // Display the input prompt to the user
            cout << endl;
            cout << "1. " << prompt << endl;
            cout << "2. Exit" << endl;

            // Check that a value is successfully read; nothing trails it;
            // and it's either 1 or 2
            if ((cin >> value) && (cin.peek() == EOF || cin.peek() == '\n')
                && ((value == 1) || (value == 2))) {
                validInput = true;
            } else {
                // Make sure to clear all the garbage out of the buffer before moving on
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid input! Must select either 1 or 2" << endl;
            }
        } while (!validInput);

        switch (value) {
            case 1:
                runProgram = true;
                break;
            case 2:
                runProgram = false;
                break;
            default:
                cout << "ERROR: Invalid main menu selection" << endl;
        }

        return runProgram;
    }
    

    /*********************************************************************
     ** Description: Prompts the user with the passed prompt string and
     **              reads in the user's input. It then checks that the
     **              input was a valid integer. If the input was valid,
     **              the function returns that value; however, if it
     **              was invalid, it displays the passed error messsage
     **              and re-prompts the user. The function will continue
     **              until a valid integer value is input.
     ** 
     ** Arguments: A string containing the prompt to display to the user;
     **            a string containing the error message to show the user
     **            when invalid values are entered; and two integers
     **            representing the first and last values, inclusive, of
     **            the range of acceptable input values. Declaration
     **            gives min and max default arguments of the system int
     **            min and max, respectively. This allows the function
     **            to be called without specifying min and max if any
     **            valid integer is acceptable.
     ** 
     ** Preconditions: min <= max, otherwise no values sasisfy the
     **                validation criteria.
     ** 
     ** Returns: An integer upon the first successful input from the user.
     *********************************************************************/
    int getValidInt(const std::string &prompt,
                    const std::string &errorMessage,
                    int min, int max) {

        // Holds the final result
        int value;

        // Flag to indicate whether we have been successful yet or not
        bool validInput = false;

        do {
            // Display the input prompt to the user
            cout << endl << prompt;
        
            // Check that a value is successfully read; nothing trails it;
            // and it's within the range specified
            if ((cin >> value) && (cin.peek() == EOF || cin.peek() == '\n')
                && (value <= max) && (value >= min)) {
                validInput = true;
            } else {
                // Make sure to clear all the garbage out of the buffer before moving on
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << errorMessage << endl;
            }
        } while (!validInput);

        // Make sure to clear all the garbage out of the buffer before moving on
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return value;
    }


    /*********************************************************************
     ** Description: Prompts the user with the passed prompt string and
     **              reads the user's input. If the initial character
     **              is a 'y', 'Y', 'n', or 'N', the function accepts the
     **              input as valid. Any input with an initial, case-
     **              insensitive y value is interpreted as yes, and any
     **              input with an initial, case-insensitive n value is
     **              interpreted as a no. If the input was invalid, the
     **              function displays an error message and re-prompts
     **              the user. The functions will continue until a valid
     **              value is input. Once a valid value is input, the
     **              function returns a Boolean value indicating
     **              whether the user responded yes (true) or no (false).
     ** 
     ** Arguments: A string used to customize the prompt for user input.
     ** 
     ** Preconditions: None.
     ** 
     ** Returns: A Boolean value indicating the user's response to a yes
     **          or no prompt. true indicates a yes answer, and false
     **          indicates a no answer.
     *********************************************************************/
    bool getYesOrNo(const std::string &prompt) {

        // Holds the letter input 
        char value;

        // Flag to indicate whether we have been successful yet or not
        bool validInput = false;

        // The final answer we return
        bool answer = false;

        do {
            // Display the input prompt to the user
            cout << endl << prompt;

            // Check that a value is successfully read and it's a valid option
            if ((cin >> value) && ((value == 'y') || (value == 'Y')
                || (value == 'n') || (value == 'N'))) {
                validInput = true;

            // Otherwise clear, warn, and keep looping
            } else {

                // Make sure to clear all the garbage out of the buffer before moving on
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Error message
                cout << "Invalid input! Must begin with \'y\' or \'Y\' for YES,"
                     << " \'n\' or \'N\' for NO" << endl;
            }
        } while (!validInput);

        // Make sure to clear all the garbage out of the buffer before moving on
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Assign the return value based on the input
        switch (value) {
            case 'y':
                // Fall through - case insensitive
            case 'Y':
                answer = true;
                break;
            case 'n':
                // Fall through - case insensitive
            case 'N':
                answer = false;
                break;
        }

        return answer;
    }


    /*********************************************************************
     ** Description: Returns a random integer from within the range
     **              bounded by the passed max and min, inclusive.
     ** 
     ** Arguments: Two integers defining the lower and upper bounds of the
     **            range the random integer should fall within. The bounds
     **            are inclusive.
     ** 
     ** Preconditions: None.
     ** 
     ** Returns: An integer within the range defined by min and max.
     *********************************************************************/
    int getRandomIntInRange(int min, int max) {
        // Ensure min and max are in the right order; swap if not
        if (min > max) {
            int temp = min;
            min = max;
            max = temp;
        }

        return min + std::rand() % (max - min + 1);
    }


    /*********************************************************************
     ** Description: Prompts the user with the passed prompt string and
     **              reads in the user's input. It then checks that the
     **              input was a single valid character. If the input was
     **              valid, the function returns that value; however, if
     **              it was invalid, it displays the passed error messsage
     **              and re-prompts the user. The function will continue
     **              until a valid character value is input.
     ** 
     ** Arguments: A string containing the prompt to display to the user;
     **            a string containing the error message to show the user
     **            when invalid values are entered; and a vector of
     **            chars which represent the valid input options.
     ** 
     ** Preconditions: validOptions must contain at least one character,
     **                otherwise no input will sasisfy the validation
     **                criteria.
     ** 
     ** Returns: A char upon the first successful input from the user.
     *********************************************************************/
    char getCharFromOptions(const std::string &prompt,
                            const std::string &errorMessage,
                            const std::vector<char> &validOptions) {

        // Holds the letter input 
        char value;

        // Flag to indicate whether we have been successful yet or not
        bool validInput = false;

        do {
            // Display the input prompt to the user
            cout << endl << prompt;

            // Check that a value is read; nothing trails; and it's a valid option
            if ((cin >> value) && (cin.peek() == EOF || cin.peek() == '\n')) {

                // Check against all valid options
                for (auto c : validOptions) {

                    // Does the value match one of the options? (case insensitive)
                    if (std::tolower(value) == c) {
                        validInput = true;
                    }
                }
            }

            if (!validInput) {

                // Make sure to clear all the garbage out of the buffer before moving on
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << errorMessage << endl;
            }
        } while (!validInput);

        // Make sure to clear all the garbage out of the buffer before moving on
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // We always return a lowercase letter to standardize
        return std::tolower(value);
    }
    
    
    /*********************************************************************
     ** Description: Prompts the user with the passed prompt and then
     **              the user's input; the function attempts to use the
     **              passed ifstream to open a file matching the name
     **              input by the user. If the file is successfully opened,
     **              the function is finished. If the file fails to open
     **              properly, the passed error message is displayed
     **              and the user is re-prompted. This loop will continue
     **              until a file is successfully opened.
     ** 
     ** Arguments: A string containing the prompt to display to the user;
     **            a string containing the error message to show the user
     **            when invalid values are entered; and a reference to an
     **            ifstream used to open the file to be read.
     ** 
     ** Preconditions: A valid file to be read must exist, otherwise the
     **                success condition will never be met.
     ** 
     ** Returns: Nothing.
     *********************************************************************/
    void openInFile(const std::string &prompt,
                    const std::string &errorMessage,
                    std::ifstream &infile){
        // A flag indicating success
        bool openSuccessful = false;

        // What we read the user's input into
        std::string filename;

        // Prompt the user until file successfully opened
        while (!openSuccessful) {
            cout << prompt;

            // Read the user's input
            std::getline(std::cin, filename);

            // Try and open the file specified by the user
            infile.open(filename);

            // If it worked, we're done; otherwise display error message
            if (infile.good()) {
                openSuccessful = true;
            } else {
                cout << errorMessage << endl;
            }
        }
    }


    /*********************************************************************
     ** Description: Prompts the user with the passed prompt and then
     **              the user's input; the function attempts to use the
     **              passed ofstream to open a file using the name
     **              input by the user. If the file is successfully opened,
     **              the function is finished. If the file fails to open
     **              properly, the passed error message is displayed
     **              and the user is re-prompted. This loop will continue
     **              until a file is successfully opened.
     ** 
     ** Arguments: A string containing the prompt to display to the user;
     **            a string containing the error message to show the user
     **            when invalid values are entered; and a reference to an
     **            ofstream used to open a file to write to.
     ** 
     ** Preconditions: None.
     ** 
     ** Returns: Nothing.
     *********************************************************************/
    void openOutFile(const std::string &prompt,
                     const std::string &errorMessage,
                     std::ofstream &outFile){

        // A flag indicating success
        bool openSuccessful = false;

        // What we read the user's input into
        std::string filename;

        // Prompt the user until file successfully opened
        while (!openSuccessful) {
            cout << prompt;

            // Read the user's input
            std::getline(std::cin, filename);

            // Try and open the file specified by the user
            outFile.open(filename);

            // If it worked, we're done; otherwise display error message
            if (outFile.good()) {
                openSuccessful = true;
            } else {
                cout << errorMessage << endl;
            }
        }
    }


    /*********************************************************************
     ** Description: Prompts the user with the passed prompt and then
     **              reads their input into a string and returns it. Will
     **              accept arbitrary input.
     ** 
     ** Arguments: A string containing the prompt to display to the user.
     ** 
     ** Preconditions: None.
     ** 
     ** Returns: A string containing the users response.
     *********************************************************************/
     std::string getString(const std::string &prompt) {
        // What we read the user's input into
        std::string input;

        cout << prompt;

        // Read the user's input
        std::getline(std::cin, input);

        return input;
     }
}
