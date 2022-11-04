#include <stdio.h>

void selection_sortx(void)
{
    int array[] = {5, 1, 2, 8, 6};
    int len = 5;
    int i = 0;

    // Iterate over array step by step
    while (i < len)
    {
        // Find min for current position of array
        int temp_min = i, j = i;

        // Find the smallest value
        while (j < len)
        {
            if (array[j] < array[temp_min])
            {
                temp_min = j;
            }

            j++;
        }

        // Switch positions
        int tmp = array[temp_min];
        array[temp_min] = array[i];
        array[i] = tmp;

        for (int idx = 0; idx < len; idx++)
        {
            printf("%i", array[idx]);
        }

        i++;
        printf("\n");
    }
}

void bubble_sortx(void)
{
    // Set swap counter to non-zero value
    int swap_counter = 5;
    int array[] = {5, 1, 2, 8, 6};
    int len = 5;

    // Repeat until swap counter is zero
    do
    {
        // Set swap counter to zero
        swap_counter = 0;
        int i = 0;
        while (i < len - 1)
        {
            // Look at each pair
            if (array[i] > array[i + 1])
            {
                // If two not in correct order, swap them
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap_counter++;
            }
            i++;
            for (int j = 0; j < len; j++)
            {
                printf("%i", array[j]);
            }
            printf("\n");
        }
    }
    while(swap_counter != 0);
}

void insertion_sortx(void)
{
    int i = 0, len = 5;
    int array[] = {5, 1, 2, 8, 6};

    int element;
    while (i < len)
    {
        // Call the first element of the array sorted
        element = array[i];
        int idx = i;

        // Repeat until all elements are sorted
        while (idx > 0 && array[idx - 1] > element)
        {
            // Look at the next unsorted element. Insert into the "sorted" position by shifting the requisite number of elements.
            array[idx] = array[idx - 1];
            idx--;
        }
        array[idx] = element;
        for(int j = 0; j < len; j++)
        {
            printf("%i", array[j]);
        }
        i++;
        printf("\n");
    }
}

/******
* Selection sort algorithm based on CS50 pseudocode
*/
void selection_sort(void)
{
    int array[] = {5, 1, 2, 8, 6};
    int array_length = 5, int index = 0;

    // iterate over array step by step
    while (index < array_length)
    {
        // Find min for current position of array
        int index_smallest_object = index, position = index;

        // Find the smallest value
        while (position < array_length)
        {
            if (array[position] < array[index_smallest_object])
            {
                index_smallest_object = position;
            }

            position++;
        }

        // Switch positions
        int placeholder = array[index_smallest_object];
        array[index_smallest_object] = array[index];
        array[index] = placeholder;

        index++;
    }
}

/******
* Bubble sort algorithm based on CS50 pseudocode
*/
void bubble_sort(void)
{
    // Set swap counter to non-zero value
    int swap_counter = 5;

    int array[] = {5, 1, 2, 8, 6};
    int array_length = 5;

    // Repeat until swap counter is zero
    do
    {
        // Set swap counter to zero
        swap_counter = 0;
        int index = 0;
        while (index < array_length - 1)
        {
            // Look at each pair
            if (array[index] > array[index + 1])
            {
                // If two not in correct order, swap them
                int placeholder = array[index];
                array[index] = array[index + 1];
                array[index + 1] = placeholder;
                swap_counter++;
            }
            index++;
        }
    }
    while(swap_counter != 0);
}

/******
* Insertion sort algorithm based on CS50 pseudocode
*/
void insertion_sort(void)
{
    int index = 0, array_length = 6;
    int array[] = {2, 5, 1, 3, 6, 4};

    int element;
    while (index < array_length)
    {
        // Call the first element of the array sorted
        element = array[index];
        int element_index = index;

        // Repeat until all elements are sorted
        while (element_index > 0 && array[element_index - 1] > element)
        {
            // Look at the next unsorted element.
            // Insert into the "sorted" position by shifting the elements.
            array[element_index] = array[element_index - 1];
            element_index--;
        }
        array[element_index] = element;
        index++;
    }
}


int main(void)
{

}
