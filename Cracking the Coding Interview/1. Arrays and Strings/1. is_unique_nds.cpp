#include<stdio.h>

int main(int argc, char *argv[]) {
    char *str = argv[1];
    char *_str = str + sizeof(char);
    int len = strlen(str);

    while (*str != '\0') {
        while (*_str != '\0') {
            if (*str == *_str) {
                printf("%c is not unique\n", *str);
                return 0;
            }
            _str++;
        }
        str++;
        _str = str + 1;
    }
    printf("All characters are unique\n");
}