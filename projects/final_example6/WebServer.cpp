/*********************************************************************
 ** Program name:
 **
 ** Author: Caleb Schmidt
 **
 ** Date: 11/21/2017
 **
 ** Description:
 *********************************************************************/

#include "WebServer.hpp"

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
WebServer::WebServer(const std::string &name) {
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
WebServer::~WebServer() {
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
void WebServer::exploit() {
    cout << "HPE SKU P/N 815101-B21 815102-B21" << endl;
    cout << "SKU Description" << endl;
    cout << "HPE 64GB 4Rx4" << endl;
    cout << "PC4-2666V-L Kit" << endl;
    cout << "HPE 128GB 8Rx4" << endl;
    cout << "PC4-2666V-L Kit" << endl;
    cout << "DIMM Rank Quad Rank (4R) Octal Rank (8R)" << endl;
    cout << "DIMM Capacity 64 GB 128 GB" << endl;
    cout << "Voltage 1.2 V 1.2 V" << endl;
    cout << "DRAM Depth 2 Gb 2 Gb" << endl;
    cout << "DRAM Width (bit) x4 x4" << endl;
    cout << "DRAM Density 8 Gb 8 Gb" << endl;
    cout << "CAS Latency 19-19-19 22-19-19" << endl;
    cout << "DIMM Native Speed (MT/s) 2666 2666" << endl;
    cout << "HPE Server Memory Speed (MT/s): Intel Xeon Platinum/Gold 81xx/61xx Processors" << endl;
    cout << "1 DIMM per Channel 2666 2666" << endl;
    cout << "2 DIMM per Channel 2666 2666" << endl;
    cout << "HPE Server Memory Speed (MT/s): Intel Xeon Gold/Silver 51xx/41xx Processors" << endl;
    cout << "1 DIMM per Channel 2400 2400" << endl;
    cout << "2 DIMM per Channel 2400 2400" << endl;
    cout << "HPE Server Memory Speed (MT/s): Intel Xeon Bronze 31xx Processors" << endl;
    cout << "1 DIMM per Channel 2133 2133" << endl;
    cout << "2 DIMM per Channel 2133 2133" << endl;
    setExploited(true);
}
