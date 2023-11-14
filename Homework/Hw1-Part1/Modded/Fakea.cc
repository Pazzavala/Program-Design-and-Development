#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> spliting(string& str) {
    vector<string> strBreakDown;
    string strPart;
    size_t prev = 0;
    size_t curr = str.find(' ');

    while (curr != string::npos) {
        strPart = str.substr(prev, curr - prev);
        strBreakDown.push_back(strPart);
        prev = curr + 1;
        curr = str.find(' ', prev);
    }

    strPart = str.substr(prev, curr - prev);
    strBreakDown.push_back(strPart);

    return strBreakDown;
}

int main() {
    string input;
    vector<string> strVector;

    cout << "Input:\n";

    getline(cin, input);

    strVector = spliting(input);

    cout << "Output:\n" << strVector.size() << endl;

    return 0;
}