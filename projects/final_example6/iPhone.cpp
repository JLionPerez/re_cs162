/*********************************************************************
 ** Program name:
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description:
 *********************************************************************/

#include "iPhone.hpp"

using std::cout;
using std::endl;


/*********************************************************************
 ** Description: Constructor. Takes a name and assignes it to the
 **              instance.
 **
 ** Arguments: A string representing the name of the device.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
iPhone::iPhone(const std::string &name) {
    setName(name);
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
iPhone::~iPhone() {
    // Nothing to do
}


/*********************************************************************
 ** Description: Handles custom exploitation logic for this subclass
 **              of Space.
 **
 ** Arguments: N/A.
 **
 ** Preconditions: None.
 **
 ** Returns: N/A.
 *********************************************************************/
void iPhone::exploit() {
    cout << "A11 Bionic chip with 64-bit architecture" << endl;
    cout << "Neural engine" << endl;
    cout << "Embedded M11 motion coprocessor" << endl;
    cout << "FDD-LTE (Bands 1, 2, 3, 4, 5, 7, 8, 12, 13, 17, 18, 19, 20, 25, 26, 28, 29, 30, 66)" << endl;
    cout << "TD-LTE (Bands 34, 38, 39, 40, 41)" << endl;
    cout << "TD-SCDMA 1900 (F), 2000 (A)" << endl;
    cout << "CDMA EV-DO Rev. A (800, 1900, 2100 MHz)" << endl;
    cout << "UMTS/HSPA+/DC-HSDPA (850, 900, 1700/2100, 1900, 2100 MHz)" << endl;
    cout << "GSM/EDGE (850, 900, 1800, 1900 MHz)" << endl;
    setExploited(true);
}
