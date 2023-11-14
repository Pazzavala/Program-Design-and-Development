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

void toLower(string& str) {
    
    for (char& ch : str) {
        ch = tolower(ch);
    }
}

int main() {
    string input;
    vector<string> strVector;
    bool polite, question;

    do {
        polite = false;
        question = false;
        cout << "Input (enter q to quit):\n";

        getline(cin, input);
        if (input == "q") break;
        
        toLower(input);
        strVector = spliting(input);

        for (string word : strVector) {
            if (word == "who" || word == "what" || word == "where"
            || word == "when" || word == "why" || word == "how")
                question = true;
            if (word == "please" || word == "may")
                polite = true;
        }

        cout << "Output:\n";

        switch (question) {
            case true:
                cout << "I’m not sure, you should google that! ";
                break;
            case false:
                cout << "That is not a question! ";
                break;
            default:
                break;
        }

        switch (polite) {
            case true:
                cout << ((question) ? ( "Thanks for asking so politely.") : ("But you said it nicely."));
                break;
            case false:
                cout << ((question) ? ("Your questions should also be more polite.") : ("And you should be more polite."));
                break;
            default:
                break;
        }

    } while (input != "q");

    return 0;
}