// https://www.codewars.com/kata/5ca24526b534ce0018a137b5/train/cpp

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string oldPhone(const string& message) {
    unordered_map<char, string> charToKeypress = {
        {'a', "2"}, {'b', "22"}, {'c', "222"},
        {'d', "3"}, {'e', "33"}, {'f', "333"},
        {'g', "4"}, {'h', "44"}, {'i', "444"},
        {'j', "5"}, {'k', "55"}, {'l', "555"},
        {'m', "6"}, {'n', "66"}, {'o', "666"},
        {'p', "7"}, {'q', "77"}, {'r', "777"}, {'s', "7777"},
        {'t', "8"}, {'u', "88"}, {'v', "888"},
        {'w', "9"}, {'x', "99"}, {'y', "999"}, {'z', "9999"},
        {'A', "#2"}, {'B', "#22"}, {'C', "#222"},
        {'D', "#3"}, {'E', "#33"}, {'F', "#333"},
        {'G', "#4"}, {'H', "#44"}, {'I', "#444"},
        {'J', "#5"}, {'K', "#55"}, {'L', "#555"},
        {'M', "#6"}, {'N', "#66"}, {'O', "#666"},
        {'P', "#7"}, {'Q', "#77"}, {'R', "#777"}, {'S', "#7777"},
        {'T', "#8"}, {'U', "#88"}, {'V', "#888"},
        {'W', "#9"}, {'X', "#99"}, {'Y', "#999"}, {'Z', "#9999"},
        {' ', "0"}, {'1', "1"}, {'2', "2"}, {'3', "3"},
        {'4', "4"}, {'5', "5"}, {'6', "6"}, {'7', "7"},
        {'8', "8"}, {'9', "9"}, {'\'', "*"}, {'-', "**"},
        {'+', "***"}, {'=', "****"}, {'#', "#"},
        {'.', "1"}, {',', "11"}, {'?', "111"}, {'!', "1111"}
    };
    
    string result = "";
    bool isUpperCase = false;  // Track the current case mode

    for (char c : message) {
        if (isupper(c)) isUpperCase = true;
        if (isalpha(c)) {
            bool shouldBeUpperCase = isupper(c);
            if (shouldBeUpperCase != isUpperCase) {
                result += "#";
                isUpperCase = shouldBeUpperCase;
            }
        }
        if (charToKeypress.find(c) != charToKeypress.end()) {
            string keyPress = charToKeypress[c];
            if (!result.empty() && result.back() == keyPress[0] && keyPress[0] != '#') {
                result += " ";
            }
            result += keyPress;
        }
    }
    return result;
}

int main() {
    string message;
    cout << "Enter message: ";
    getline(cin, message);

    string keypresses = oldPhone(message);
    cout << "==============================\n";
    cout << "Message to send: " << message << endl;
    cout << "Keypresses: " << keypresses << endl;

    return 0;
}
