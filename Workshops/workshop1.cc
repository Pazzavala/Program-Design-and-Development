#include <iostream>
#include<string.h>
#include<string>
#include <vector>
#include <bitset>
using namespace std;

bitset<8> toBinary(int num) {
    return bitset<8>(num);
}

int main() {
    
    string classType;
    string mask;
    int sections = 4;
    vector<int> sectionNums(sections);
    
    do {
        cout << "\n\nEnter IP (or q to exit): ";
        cin >> ipAddress;

        if (ipAddress != "q") {
            cout << "\nThe address " << ipAddress;

            // Divide each section by '.' and save each number in between
            size_t curr;

            for (int i = 0; i < sections; i++) {
                size_t prev = 0;

                if (i == sections - 1) {
                    sectionNums.at(i) = stoi(ipAddress);
                } else {
                    curr = ipAddress.find('.');
                    sectionNums.at(i) = stoi(ipAddress.substr(prev, curr));
                    ipAddress = ipAddress.substr(curr + 1, ipAddress.size());
                }
            }

            // Identify class of given IP address
            if (sectionNums.at(0) >= 0 && sectionNums.at(0)  < 128) {
                classType = "Class A";
                mask = "255.0.0.0";
            } else if (sectionNums.at(0)  >= 128 && sectionNums.at(0)   < 192) {
                classType = "Class B";
                mask = "255.255.0.0";
            } else {
                classType = "Class C";
                mask = "255.255.255.0";
            }
                
            // Print info about the IP adress
            cout << " is " << classType << " address.\n";
            cout << "The default subnet mask is " << mask << endl;
            cout << "The IP address converts to ";

            for (int i = 0; i < sections; i++) {
                cout << toBinary(sectionNums.at(i));
                if (i != sections - 1) 
                    cout << ".";
            }
        }

    } while (ipAddress != "q");
    

    return 0;
}