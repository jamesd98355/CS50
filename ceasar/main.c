// CEASARS CYPHER:
// Take command line argument (int)
// Ask for text from user
// apply cypher of int to the text


// might want to include it for uppercase letters

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cypher_text(char text[], int x);

int main(void) {
    char text[100];
    int cypher_level = 0;

    printf("Text: ");
    scanf("%[^\n]s", text);

    printf("Cypher level (int): ");
    scanf("%i", &cypher_level);

    cypher_text(text, cypher_level);

    printf("%s", text);

    return 0;
}

char cypher_text(char text[], int x)
{
    int letter_number = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            text[i] = tolower(text[i]);
            letter_number = text[i] - 97;
            text[i] = (letter_number + x)%26;
            text[i] = text[i] + 97;
        }
    }
    return text;
}
