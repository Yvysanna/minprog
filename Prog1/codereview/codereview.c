#include <stdio.h>


// Indentation check, Spaces check, bracket placing
int main(void)
{
    // print arguments
    printf("\n");

    for (int i = 0; i < argc; i++)
    {
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            printf("%c\n", argv[i][j]);
        }
    printf("\n");
    }
}
