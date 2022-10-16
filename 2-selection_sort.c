#include "sort.h"
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * selection_sort - sorts an array of integer inascending order
 * @array: an array of elements
 * @size: size of the array
 * Return: sorted array
 */
 void selection_sort(int *array, size_t size)
 {
    int i, j, min;

    for (i = 0; i < size -1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        if (array[j] < array[min])
        min = j;
        swap(&array[min], &array[i]);
        print_array(array, size);        
    }
    
 }

