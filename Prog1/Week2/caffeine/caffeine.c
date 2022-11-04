// Greedy opdracht om de gebruiker de zeggen welke en hoe veel caffeine drankjes hij kan consumeren

#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Struct for drinks and their caffeine
typedef struct{
    char drink[20]; 
    int caffeine;
    int count;
} Drink;

// Name of drink, amount of caffeine in mg
Drink drinks[] = {
    {"espresso", 70, 0}, 
    {"black tea", 30, 0}, 
    {"green tea", 20, 0}, 
    {"cocoa", 10, 0}, 
    {"piece of chocolate", 1, 0}
};


int main(void){
    float grams;

    // Do while because we need at least one prompt; do not allow negative numbers
    do {
        grams = get_float("Amount in grams: ");
    } while (grams <= 0.001);

    // Round to convert float of g into into int mg correctly
    int caffeine = round(grams * 1000);

    // Total amount of drinks
    int total = 0;
    char buffer[22];

    // Iterate over each drink
    for (int i = 0; i < 5; i++) {

        // Check for each drink if given caffeine greater
        while (caffeine >= drinks[i].caffeine){
            caffeine -= drinks[i].caffeine;
            drinks[i].count++;

            // Add drink to total drink count (if not chocolate)
            if (i != 4){
                total++;
            }

            // Loop will be stopped after this, so print now
            if (caffeine < drinks[i].caffeine){
                sprintf(buffer, "%d %s\n", drinks[i].count, drinks[i].drink);
                printf("%s", buffer);
            }
        }
    }

    // Take care of singular or plural
    char* plural = "drinks";
    if (total == 1){
        plural = "drink";
    }

    printf("That makes %d %s in total\n", total, plural);
    
}
