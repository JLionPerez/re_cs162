/*********************************************************************
 ** Program name:
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description:
 *********************************************************************/

#include "Server.hpp"

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
Server::Server(const std::string &name) {
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
Server::~Server() {
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
void Server::exploit() {
    cout << "One 10/100 Mbps UTP port and one 100 Mbps fiber optic port" << endl;
    cout << "16 MB of internal memory" << endl;
    cout << "Capable of accepting HTML files, PDF files, Active X, CRG, GIF, JPG graphics, MS Office files" << endl;
    cout << "(doc, xls, ppt, etc.)" << endl;
    cout << "Configurable remotely using a standard internet browser" << endl;
    cout << "One RS-485 serial port and a second port configurable for RS-232" << endl;
    cout << "or RS-485 (support for 2-wire or 4-wire)" << endl;
    cout << "Protocols supported: Ethernet – MODBUS / TCP HTTP, FTP. Serial – MODBUS, JBUS, SY/MAX" << endl;
    cout << "Input voltage: 24 Vdc; maximum burden 8 Watts" << endl;
    cout << "Ambient temperature of -30 to 80° C; relative humidity 5 to 95%" << endl;
    setExploited(true);
}
