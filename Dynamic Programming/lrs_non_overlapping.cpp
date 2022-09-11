// Given a string find the longest substring that repeats
// at least once and doesn't overlap. For example for the
// string 'aababaab' the longest repeating substring would be 'aab'
#include <iostream>

using namespace std;

string brute_force(string &str) {
    string longest = "";
    int longest_size = 0;
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (j - i > longest_size) {
                string current_substr = str.substr(i, j);
                string current_removed = str.substr(0, i) + str.substr(j);
                if (current_removed.find(current_substr) != str.npos) {
                    longest = current_substr;
                    longest_size = current_substr.length();
                }
            }
        }
    }
    return longest;
}

int main() {
    string str;
    cin >> str;

    cout << brute_force(str) << endl;
}