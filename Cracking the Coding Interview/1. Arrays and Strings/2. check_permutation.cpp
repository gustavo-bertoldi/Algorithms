#include<stdio.h>

int main(int argc, char* argv[]) {
    char* str1 = argv[1];
    char* str2 = argv[2];
    int str1_chars[128] = {0};
    int str2_chars[128] = {0};

    while (*str1 != '\0' && *str2 != '\0') {
        str1_chars[*str1++] += 1;
        str2_chars[*str2++] += 1;
        if ((*str1 == '\0' || *str2 == '\0') && (*str1 != *str2)) {
            printf("strings are not a permutation of each other\n");
            return 0;
        }
    }

    for (int i = 0; i < 128; i++) {
        if (str1_chars[i] != str2_chars[i]) {
            printf("strings are not a permutation of each other\n");
            return 0;
        }
    }

    printf("strings are a permutation\n");
    return 0;
}