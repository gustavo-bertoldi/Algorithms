#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int allocated; /* current allocation of array */
    int filled;    /* number of items present in the binary heap */
    int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the member array with the given size
 * it also fill allocated (size) and initializes
 * filled to 0 */
BinaryHeap *Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap *heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap *heap, int *val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap *heap);

int main(void)
{
    char lecture[100];
    int val;
    BinaryHeap *heap;
    heap = Init(10);

    fscanf(stdin, "%99s", lecture);
    while (strcmp(lecture, "bye") != 0)
    {
        if (strcmp(lecture, "insert") == 0)
        {
            fscanf(stdin, "%99s", lecture);
            val = strtol(lecture, NULL, 10);
            InsertValue(heap, val);
        }
        else if (strcmp(lecture, "extract") == 0)
        {
            if (ExtractMax(heap, &val))
            {
                printf("%d\r\n", val);
            }
        }
        fscanf(stdin, "%99s", lecture);
    }
    Destroy(heap);
    return 0;
}

BinaryHeap *Init(int size)
{
    BinaryHeap *heap;
    heap -> array = (int*)malloc(size * sizeof(int));
    heap -> allocated = size;
    heap -> filled = 0;
    return heap;
}

void InsertValue(BinaryHeap *heap, int value)
{
    //Insertion at the end first
    heap -> array[heap -> filled] = value;
    heap -> filled += 1;
    int parent = ((heap -> filled) - 1) / 2;
    while (1) {
        int parent = heap -> array[parent];
    }
}

int ExtractMax(BinaryHeap *heap, int *res)
{
    /* put your extraction code here */
    return 0;
}

void Destroy(BinaryHeap *heap)
{
    /* put your destruction code here */
}
