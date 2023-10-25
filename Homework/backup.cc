#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

// --------------- Helper functions ---------------
vector<int> buildMask(int num, bool inverse = false) {
    bitset<32> bitSubnetMask;
    vector<int> subnetMask;
    
    for (int i = 0; i < num; i++)
        bitSubnetMask.set(i);
    
    if (inverse)
        bitSubnetMask = ~bitSubnetMask;

    for (int i = 0; i < 4; ++i) {
        int section = 0;
        for (int j = 0; j < 8; ++j) {
            section <<= 1;
            section |= bitSubnetMask[i * 8 + j];
        }
        subnetMask.push_back(section);
    }

    return subnetMask;
}
----------------------------------------------------

class IPAddress {
    private:
        vector<int> ipOctets;
        vector<int> smOctets;
    public:
        IPAddress(vector<int> ipOct, vector<int> smOct): ipOctets(ipOct), smOctets(smOct) {};
        vector<int> calculateNetworkAddress();
        vector<int> calculateBroadcastAddress();
        pair<vector<int>, vector<int>> calculateValidIPAddressRange();
};

vector<int> IPAddress::calculateNetworkAddress() {
    vector<int> networkAddress;
    vector<int> mask = buildMask(smOctets.at(0));
    

    for (int i = 0; i < ipOctets.size(); i++) {
        networkAddress.push_back(ipOctets.at(i) & mask.at(i));
    }

    return networkAddress;
}

vector<int> IPAddress::calculateBroadcastAddress() {
    vector<int> broadcastAddress;
    vector<int> mask = buildMask(smOctets.at(0), true);

    for (int i = 0; i < ipOctets.size(); i++) {
        broadcastAddress.push_back(ipOctets.at(i) | mask.at(i));
    }
    
    return broadcastAddress;
}

pair<vector<int>, vector<int>> IPAddress::calculateValidIPAddressRange() {
    pair<vector<int>, vector<int>> pair = make_pair(this->calculateNetworkAddress(), this->calculateBroadcastAddress());
    return pair;
}

// --------------- Helper functions ---------------

void printAddress(vector<int> address) {
    int size = address.size();
    for (int i = 0 ; i < size; i++) {
        cout << address.at(i);
        if (i != size - 1) 
            cout << ".";
    }
}

/* Divide an addres by the delimiter '.' */
vector<int> addressDivider(string& address) {
    vector<int> addressSections;
    int num;
    size_t prev = 0;
    size_t curr = address.find('.');

    while (curr != string::npos) {
        num = stoi(address.substr(prev, curr - prev));
        addressSections.push_back(num);
        prev = curr + 1;
        curr = address.find('.', prev);
    }

    num = stoi(address.substr(prev, curr - prev));
    addressSections.push_back(num);

    return addressSections;
}
// ----------------------------------------------------

int main() {
    string input; 
    vector<int> ipAddress, submask, networkAddress, broadcastAddress;
    
    int addySize;
    bool validInput = true;

    do {
        cout << "\nEnter IPv4 address[xxx.xxx.xxx.xxx] (or Type q to exit): ";
        cin >> input;

        if (input != "q") {
            ipAddress = addressDivider(input);
            addySize = ipAddress.size();
            if (addySize != 4) {
                cout << "\nInvalid IPAdress!";
            } else {
                cout << "\nEnter a subnet mask [1-32] (or Type q to exit): ";
            
                while (!(cin >> input) || stoi(input) < 1 || stoi(input) > 32) {
                    cout << "Invalid submask, Enter again: ";
                    // migth have to clear error.
                    // might have to clear remainding input.
                }

                submask.push_back(stoi(input));
                IPAddress ip(ipAddress, submask);

                networkAddress = ip.calculateNetworkAddress();
                cout << "Network Address: ";
                printAddress(networkAddress);
                cout << endl;
             
                broadcastAddress = ip.calculateBroadcastAddress();
                cout << "Broadcast Address: ";
                printAddress(broadcastAddress);
                cout << endl;

                pair<vector<int>, vector<int>> range = ip.calculateValidIPAddressRange();

                cout << "Valid IP Address Range: ";
                printAddress(range.first);
                cout << " - ";
                printAddress(range.second);
                cout << endl;
                
            }
        }
    } while (input != "q");

    // bitset<8> binaryAddress("00110010");
    // bitset<8> binaryAddress2("00001111");
    // cout << endl;   

    // cout << (binaryAddress | binaryAddress2);

    return 0;
}