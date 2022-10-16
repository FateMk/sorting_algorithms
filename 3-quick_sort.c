#include "sort.h"
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

 void quick_sort(int *array, size_t size)
 {
    size_t i, j, last, first, pivot, temp;
    first = 0;
    last = (size -1);
    pivot = first;
    i = first;
    j = last;

    while (i < j)
    {
        while (array[i] <= array[pivot] && i < last)
        {
            i++;
            if (i < j)
            {
                swap(&array[i], &array[j]);
            }
        }
        swap(&array[pivot], &array[j]);
        quick_sort(array, size);
    }
 
 }

 
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

 int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
