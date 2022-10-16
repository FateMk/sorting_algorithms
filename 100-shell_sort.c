#include "sort.h"

/**
 * shell_sort - sorts an array of intgers in ascending order
 * @array: array of integers
 * @size: size of the array
 * Return: sorted array
 */
 void shell_sort(int *array, size_t size)
 {
    size_t i, j, element = 0, temp;
    for ( ; element < array[size -1]; element++)
    {
        
        for (i = element; i < size; i += 1)
        {
            temp = array[i];
            for (j = i; (j >= element) && (array[j - element] > temp); j -= element)
            {
                array[j] = array[j - element];
            }
            array[j] = temp;
        }
        print_array(array, size);
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
    int array[]={49, 23, 56, 79, 89, 99, 70, 12, 7, 101, 203, 4};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");    
    print_array(array, n);
    return (0);
    
}