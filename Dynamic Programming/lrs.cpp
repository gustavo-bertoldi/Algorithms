// Given a string find the longest substring that repeats
// at least once with overlapping possibility. For example for the
// string 'babab' the longest repeating substring would be 'bab'
#include <iostream>

using namespace std;

string& max_string(string &str1, string &str2) {
    return str1.length() >= str2.length() ? str1 : str2;
}

//O(n^2)
string dynamic_programming(string &str) {
    string state[str.length() + 1][str.length() + 1];
    string longest = "";

    for (int row = str.length(); row >= 0; row--) {
        for(int col = str.length(); col >= 0; col--) {
            if (row == str.length() || col == str.length()) {
                state[row][col] = "";
            } 
            else if (str[row] == str[col] && row != col) {
                state[row][col] = str[row] + state[row + 1][col + 1];
                if (state[row][col].length() > longest.length())
                    longest = state[row][col];
            } 
            else {
                state[row][col] = "";
            }
        }
    }
    return longest;
}


//O(n^3)
string brute_force(string &str) {
    string longest = "";
    int longest_size = 0;
    for (int i = 0; i < str.length(); i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (j - i > longest_size) {
                string current_substr = str.substr(i, j);
                cout << i << " " << j << " " << current_substr << endl;
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
    cout << dynamic_programming(str) << endl;
}