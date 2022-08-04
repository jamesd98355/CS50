#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_numbers(char text);
int count_words(char text);
int count_sentences(char text);


int main(void)
{
    char text[500];

    //take user input of text
    scanf("%[^\n]s", text);

    //count number of letters
    printf("%i", count_numbers(*text));

    //count number of  words seperated with a space


    //count number of sentencces with ". ! ?"
}

int count_numbers(char text)
{
    int count = 0;
    for(int i = 0; i < strlen(&text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}