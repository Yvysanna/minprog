#include <stdio.h>

int main(void)
{
    int height = 15;
    int width = 5;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (i % width); j++)
        {
            printf(".");
            if (i % width == 0)
            {
                break;
            }
        }
        printf("#");
        printf("\n");
    }
}
