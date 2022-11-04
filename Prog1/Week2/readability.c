// Readability tests to classify text as easy or hard to read

// L = aantaal letters in text
// S = aantaal zinnen in text
// index = 0.0588 * L - 0.296 * S - 15.8


#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// For loop more elegant but if more efficient
int is_symbol(int letter){

    // Count number of sentences in the text
    string symbols = "?!.";

    for (int i = 0; i < strlen(symbols); i++){
        if (letter == (int) symbols[i]){
            
            // Early break out of function
            return 1;
        }
    }
    return 0;
}

float calculate_avg(int num, int words){
    return (100 / (float) words) * (float) num;
}




void functional(string text){

    int letter = 0; int sentence = 0; int word = 1;
    //string text = get_string("%s", "Text: ");

    // Define strlen() in variable is more efficient
    for (int i = 0, l = strlen(text); i < l; i++){
        
        // Count number of letters
        if (isalpha(text[i])){
            letter++;
        } 

        // If space, count as word
        else if (isspace(text[i])) {
            word++;
        } 

        // Count sentence if symbol in text
        else if (is_symbol(((int) text[i])) > 0){
            sentence++;
        }
    }

    float l = calculate_avg(letter, word);
    float s = calculate_avg(sentence, word);

    int result = round(0.0588 * l - 0.296 * s -  15.8);

    string print = " Grade ";
    char buffer[16];

    // Writes text into char array buffer / formats text into buffer
    if (result < 1) {
        sprintf(buffer, "Before Grade %d\n", 1);
    } 
    else if (result > 16) {
        sprintf(buffer, "Grade %d+\n", 16);
    } 
    else {
        sprintf(buffer, "Grade %d\n", result);
    }

    printf("%s", buffer);
}


int main(void) {
    functional("One fish. Two fish. Red fish. Blue fish.");
    functional("Would you like them here or there? I would not like them here or there. I would not like them anywhere.");
    functional("Congratulations! Today is your day. You're off to Great Places! You're off and away!");
    functional("Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.");
    functional("In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.");
    functional("Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, 'and what is the use of a book,' thought Alice 'without pictures or conversation?'");
    functional("When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.");
    functional("There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.");
    functional("It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.");
    functional("A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.");
}