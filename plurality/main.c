#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char* name;
    int votes;
}
        candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char* name);
void print_winner(void);

int main(void)
{
//    =======================================
// Hard code argc because cant get command line arguments to work with clion
    char argv = {""}; // arguments after file is fun
    char argc = strlen(sizeof(argv) + 1); // number of arguments including the  filename, therefore +1
//    =======================================

    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    scanf("Number of voters: ", voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char* name;
        scanf("Vote: ", name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(char* name)
{
    // TODO
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    return;
}