#include "bubble.c"
#include "merge.c"
#include "selection.c"
#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d",array[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

int main(int argc, char** argv) {
    const int size = 10;
    int a[size];
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 100;
    }

    printf("Before\n");
    print_array(a, size);

    merge_sort(a, size);

    printf("After\n");
    print_array(a, size);
    
    return 0;
}