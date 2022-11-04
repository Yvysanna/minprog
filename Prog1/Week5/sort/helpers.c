// Helper functions

#include <cs50.h>

#include "helpers.h"

// Sorts array of n values - O(n^2) sorting algorithm
void sort(int values[], int n)
{
    // Iterate over array, do not consider last number
    for (int idx = 0; idx < n - 1; idx++)
    {
        // Look from left to right, for each number, consider all numbers right of it
        for (int pos = idx + 1; pos < n; pos++)
        {
            // For each combination of numbers, if first one larger, swap
            if (values[pos] < values[idx])
            {
                int temp = values[pos];
                values[pos] = values[idx];
                values[idx] = temp;
            }
        }
    }
    return;
}
