#include <limits.h>

void selection_sort(int* array, int size) {

    for (int i = 0; i < size; i++) {
        int min = INT_MAX;
        int min_idx = 0;
        for (int j = i; j < size; j++) { 
            if (array[j] < min) {
                min = array[j];
                min_idx = j;
            }
        }
        array[min_idx] = array[i];
        array[i] = min;
    }
}