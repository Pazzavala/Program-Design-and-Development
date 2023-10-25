#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

// --------------- Helper functions ---------------

bitset<8> toBinary(int num) {
    return bitset<8>(num);
}

/* Conver a int vector to a vector with binary numbers */
vector<bitset<8>> addressToBinary(vector<int> addressVect) {
    vector<bitset<8>> binaryAddress;

    for (int num : addressVect)
        binaryAddress.push_back(toBinary(num));
    
    return binaryAddress;
}
// ----------------------------------------------------

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
    vector<bitset<8>> bitMask = addressToBinary(smOctets);
    vector<bitset<8>> bitIp = addressToBinary(ipOctets);

    for (int i = 0; i < ipOctets.size(); i++) {
        bitset<8> bits= bitMask.at(i) & bitIp.at(i);
        networkAddress.push_back(bits.to_ulong());
    }

    return networkAddress;
}

vector<int> IPAddress::calculateBroadcastAddress() {
    vector<int> broadcastAddress;
    vector<bitset<8>> bitMask = addressToBinary(smOctets);
    vector<bitset<8>> bitIp = addressToBinary(ipOctets);

    for (int i = 0; i < ipOctets.size(); i++) {
        bitset<8> inverse = ~bitMask.at(i);
        // inverse = ~inverse;
        bitset<8> bits = inverse | bitIp.at(i);
        broadcastAddress.push_back(bits.to_ulong());
    }
    
    return broadcastAddress;
}

pair<vector<int>, vector<int>> IPAddress::calculateValidIPAddressRange() {
    pair<vector<int>, vector<int>> pair = make_pair(this->calculateNetworkAddress(), this->calculateBroadcastAddress());
    return pair;
}

// --------------- Helper functions ---------------

vector<int> buildMask(int num) {
    bitset<32> bitSubnetMask;
    vector<int> subnetMask;
    
    for (int i = 0; i < num; i++)
        bitSubnetMask.set(i);

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

int countChar(string str, char target) {
    int count = 0;

    for (char ch: str) {
        if (ch == target)
            count++;
    }

    return count;
}   
// ----------------------------------------------------

int main() {
    string input; 
    vector<int> ipAddress, submask, networkAddress, broadcastAddress;
    
    int addySize;
    bool validInput = true;

    cout << "\nEnter IPv4 address [xxx.xxx.xxx.xxx]: ";
    
    while (!(cin >> input) || stoi(input) < 0 || stoi(input) > 255 || countChar(input, '.') != 3) {
        cout << "\nInvalid IPAdress! Enter again [xxx.xxx.xxx.xxx] (0 - 255): \n";
    }
    
    ipAddress = addressDivider(input);
                
    cout << "\nEnter a subnet mask [1-32]: ";

    while (!(cin >> input) || stoi(input) < 1 || stoi(input) > 32) {
        cout << "Invalid submask, Enter again: ";
    }

    submask = buildMask(stoi(input));
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

    return 0;
}

