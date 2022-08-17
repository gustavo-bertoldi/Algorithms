#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
    //Palindrome conditions
    //If nb letters is even: All letters must be in pairs
    //If nb letters is odd: All letters must be in pairs except for one

    char *input = argv[1];
    int bits[4] = {0}; //For the 127 ASCII characters

    while (*input != '\0') {
        int idx = *input / 32;
        bits[idx] |= (1 << (*input % 32));
        input++;
    }

    bool is_pal_perm = false;
    if (strlen(input) % 2 == 0) {
        for (int v: bits) {
            if (v == 0) is_pal_perm = true;
            else {
                is_pal_perm = true;
                break;
            }
        }
    } 
    else {
        for (int v: bits) {
            if (v != 0 && ((v - 1) & v) == 0) {
                if (is_pal_perm) {
                    is_pal_perm = false;
                    break;
                }
                is_pal_perm = true;
            }
        }
    }

    if (is_pal_perm) cout << "Is a palindrome permutation" << endl;
    else cout << "Is not a palindrome permutation" << endl;
}