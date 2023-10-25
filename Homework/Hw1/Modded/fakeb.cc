#include <iostream>
#include <string>
#include <vector>
#include <cctype>

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

string removeNonAlpha(string str) {
    string modStr;

    for (char& ch : str)
        if (isalpha(str) || isspace(c))
            modStr += ch;
    
    return modStr;
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
        
        string modInput = removeNonAlpha(input);
        toLower(modInput);
        strVector = spliting(modInput);

        for (string word : strVector) {
            if (word == "who" || word == "what" || word == "where"
            || word == "when" || word == "why" || word == "how")
                question = true;
            if (word == "please" || word == "may")
                polite = true;
        }

        cout << "Output:\n";

        if (question && polite)
            cout << "I’m not sure, you should google that! Thanks for asking so politely.";
        else if (question)
            cout << "I’m not sure, you should google that! Your questions should also be more polite.";
        else if (polite)
            cout << "That is not a question! But you said it so nicely.";
        else
            cout << "That is not a question! And you should be more polite.";
    } while (input != "q");

    return 0;
}