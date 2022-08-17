#include <stdio.h>
#include <stdlib.h> //For atoi

int main(int argc, char *argv[]) {
    char* str = argv[1];
    int len = atoi(argv[2]);

    
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            for (int j = len - 1; j > i; --j) {
                str[j + 2] = str[j];
            }
            len += 2;
            str[i++] = '%';
            str[i++] = '2';
            str[i] = '0';
        }
    }
    printf("%s\n", str);

}

// a b c   d e f  
// 0 1 2 3 4 5 6 7 8