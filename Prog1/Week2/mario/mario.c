// Mario

// Create pyramid in C using hashes for bricks

#include <stdio.h>
#include <cs50.h>

int main(void){
    
    int height = 0;
    do {
        height = get_int("Height: ");
    } while (height <= 0 || height > 8);

    for (int i = 0; i < height; i++){
        for (int j = height - 1; j > i; j--){
             printf("%s", " ");
        }
        for (int k = 0; k <= i; k++){
            printf("%s", "#");
        }
        printf("%s", "\n");
    }
}


