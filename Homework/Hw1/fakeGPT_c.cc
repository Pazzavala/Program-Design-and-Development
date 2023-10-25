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

string removeNonAlpha(string str) {
    string modStr;

    for (char& ch : str)
        if (isalpha(ch) || isspace(ch))
            modStr += ch;
    
    return modStr;
}

int main() {
    string input;
    vector<string> strVector;
    bool polite, question;

    polite = false;
    question = false;

    getline(cin, input);
    
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
            cout << ((question) ? ( "Thanks for asking so politely.") : ("But you said it so nicely."));
            break;
        case false:
            cout << ((question) ? ("Your questions should also be more polite.") : ("And you should be more polite."));
            break;
        default:
            break;
    }

    return 0;
}