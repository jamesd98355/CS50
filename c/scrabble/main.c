#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute_score(char word[10]);
int points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main(void)
{
    char first_word[10];
    char second_word[10];

    printf("First Word:  ");
    scanf("%s", first_word);
    printf("%s\n",first_word);

    printf("Second Word: ");
    scanf("%s", second_word);
    printf("%s\n", second_word);


    int score1 = compute_score(first_word);
    int score2 = compute_score(second_word);

    printf("score 1: %i\n", score1);
    printf("Score 2: %i\n", score2);

    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }else
    {
        printf("Draw!\n");
    }
}
int compute_score(char word[10])
{
    int score = 0;
    for(int i = 0, len = strlen(word); i < len; i++)
    {
        word[i] = toupper(word[i]);
        score += points[word[i] - 'A'];
    }
    return score;
}