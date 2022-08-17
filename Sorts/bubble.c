void bubble_sort(int* array, int size) {
    int finished = 1;
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= i + 1; j--) { 
            if (array[j] < array[j - 1]) {
                finished = 0;
                int tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
        if (finished) break;
    }
}





