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
    char* argv[] = {"Alice", "Bob"};                          // arguments after file is run
    int argc = 3;   // number of arguments including the  filename, therefore +1
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
    printf("Number of voters: ");
    scanf("%i", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[10];
        printf("Vote: ");
        scanf("%s", name);

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
//    vote takes a single argument, a string called name, representing the name of the candidate who was voted for.
//    If name matches one of the names of the candidates in the election, then update that candidate’s vote total to account
//    for the new vote. The vote function in this case should return true to indicate a successful ballot.
//    If name does not match the name of any of the candidates in the election, no vote totals should change, and the vote
//    function should return false to indicate an invalid ballot.
//    You may assume that no two candidates will have the same name.
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name))
        {
            candidates->votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
//    The function should print out the name of the candidate who received the most votes in the election, and then print a newline.
//    It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case,
//    you should output the names of each of the winning candidates, each on a separate line.

    // TODO
    candidate highest_candidate = candidates[0];
    for(int i = 1; i < candidate_count; i++)
    {
        if(highest_candidate.votes < candidates[i].votes)
        {
            highest_candidate = candidates[i];
        }
    }
    printf("Winner: %s", highest_candidate.name);
}