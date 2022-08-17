void _merge(int* array, int* aux, int low_b, int middle, int high_b) {
    //Copy both halves into the auxiliary array
    for (int i = low_b; i <= high_b; i++) aux[i] = array[i];

    int aux_left = low_b;
    int aux_right = middle + 1;
    int current = low_b;

    while (aux_left <= middle && aux_right <= high_b) {
        if (aux[aux_left] <= aux[aux_right]) {
            array[current] = aux[aux_left];
            aux_left++;
        } else {
            array[current] = aux[aux_right];
            aux_right++;
        }
        current++;
    }

    int remaining = middle - aux_left;
    for (int i = 0; i <= remaining; i++) array[current + i] = aux[aux_left + 1];
}

void _merge_sort(int* array, int* aux, int low_b, int high_b) {
    if (low_b < high_b) {
        int middle = (low_b + high_b) / 2;
        _merge_sort(array, aux, low_b, middle);
        _merge_sort(array, aux, middle + 1, high_b);
        _merge(array, aux, low_b, middle, high_b);
    }
}

void merge_sort(int* array, int size) {
    int aux[size];
    _merge_sort(array, aux, 0, size - 1);
}