#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int bits[4] = {0}; //4*32 bits = 128 bits for ASCII characters
    char* str = argv[1];

    while (*str != '\0') {
        int idx = (int)*str / 32;
        if (bits[idx] & (1 << *str)) {
            cout << *str << " is not unique" << endl;
            return 0;
        }
        bits[idx] |= (1 << *str);
        ++str;
    } 
 
    cout << "All characters are unique" << endl;
    return 0;
}