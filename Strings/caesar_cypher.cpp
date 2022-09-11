#include <iostream>

using namespace std;

int main() 
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    for (char &c: s) {
        int new_c = (int)c;
        if (new_c >= 65 && new_c <= 90) {
            new_c += (k % 26);
            if (new_c > 90) new_c = 65 + new_c - 90 - 1;
        } else if (new_c >= 97 && new_c <= 122) {
            new_c += (k % 26);
            if (new_c > 122) new_c = 97 + new_c - 122 - 1;
        }
        c = (char)new_c;
    }

    cout << s << endl;

}