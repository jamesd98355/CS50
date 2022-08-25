#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);


int main(void) {
    char text[1000];
    float letters;
    float words;
    float sentences;

    //take user input of text
    scanf("%[^\n]s", text);

    //count number of letters
    letters = count_letters(text);

    //count number of  words seperated with a space
    words = count_words(text);

    //count number of sentences with ". ! ?"
    sentences = count_sentences(text);

    // equation given to calculate readability of text
    float L = letters/words * 100;
    float S = sentences/words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = (int)round(index);

    if (rounded_index >= 16)
    {
        printf("Grade 16+");
    }
    else if (index < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade: %i", rounded_index);
    }
}

int count_letters(char text[]) {
    int count = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            count++;
        }
    }
    return count;
}

int count_words(char text[])
{
    int count = 1;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    return count;
}

int count_sentences(char text[])
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.') {
            count++;
        }
    }
    return count;
}