/** Workshop 1 
 *  CSCI3081W Fall 2023 - Shonal Gangopadhyay
 *  Solution - Shonal Gangopadhyay
 *  Feel free to use snippets of my code for other tasks.
 *  Please cite this source appropriately.
 **/

// Includes - I use strings and also bitset
#include <iostream>
#include <string>
#include <bitset>

// Main function - driver code for the system
int main() {
    
    // store the input
    std::string ipAddress;
    
    // loop
    while (true) {
        // get input
        std::cout << "Enter an IP address (or q to exit): ";
        std::cin >> ipAddress;
        
        // a way to exit
        if (ipAddress == "q") {
            break;
        }
        
        // parse IP into octets
        int octet1, octet2, octet3, octet4;
        sscanf(ipAddress.c_str(), "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
    
        // find class based on octet 1
        if (octet1 >= 1 && octet1 <= 127) {
            std::cout << "Class A address" << std::endl;
            std::cout << "Default Subnet Mask: 255.0.0.0" << std::endl;
        } else if (octet1 >= 128 && octet1 <= 191) {
            std::cout << "Class B address" << std::endl;
            std::cout << "Default Subnet Mask: 255.255.0.0" << std::endl;
        } else if (octet1 >= 192 && octet1 <= 223) {
            std::cout << "Class C address" << std::endl;
            std::cout << "Default Subnet Mask: 255.255.255.0" << std::endl;
        } else {
            std::cout << "Invalid IP address." << std::endl;
            return 1;
        }
    
        // print ip in binary
        std::cout << "IP Address in Binary: ";
        std::cout << std::bitset<8>(octet1) << "." << std::bitset<8>(octet2) << "." << std::bitset<8>(octet3) << "." << std::bitset<8>(octet4) << std::endl;
    } // end of while loop
    
    return 0;
}