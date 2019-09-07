/*********************************************************************
 ** Program name: finalproject
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description: Defines the DesktopPC class, which inherits from the
 **              Space class. Represents a Desktop PC with four network
 **              connections. Overrides the exploit member funtion and
 **              specializes it for this class.
 *********************************************************************/

#include "DesktopPC.hpp"

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
DesktopPC::DesktopPC(const std::string &name) {
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
DesktopPC::~DesktopPC() {
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
void DesktopPC::exploit() {
    cout << "CPU: 2.6GHz Intel Core i7-6700HQ (quad-core, up to 3.5GHz with Turbo Boost)" << endl;
    cout << "GPU: Nvidia GeForce GTX 970M (3GB GDDR5); Intel HD Graphics 530" << endl;
    cout << "RAM: 16GB DDR4" << endl;
    cout << "Screen: 17.3-inch, full HD 1,920 x 1,080, IPS LCD" << endl;
    cout << "Storage: 128GB SSD; 1TB HDD (7,200rpm)" << endl;
    cout << "Optical Drive: 6x Blu-ray/DVD combo drive" << endl;
    cout << "Ports: 4 x USB 3.0, 1 x USB 3.1 Type-C, HDMI, mini DisplayPort, 1 x RJ-45 LAN" << endl;
    cout << "Connectivity: 802.11ac Wi-Fi, Bluetooth 4.0" << endl;
    setExploited(true);
}
