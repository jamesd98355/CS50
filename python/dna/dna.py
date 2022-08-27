import csv
from nis import match
import sys


def main():

    # TODO: Check for command-line usage
    # filename databases sequences
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py database sequence")


    # TODO: Read database file into a variable
    dna_database = []
    with open(sys.argv[1]) as file:
        dna_reader = csv.DictReader(file)
        dna_database = list(dna_reader)

    # TODO: Read DNA sequence file into a variable
    dna_sequence = []
    with open(sys.argv[2]) as file:
        dna_sequence = file.read()
    

    


    # TODO: Find longest match of each STR in DNA sequence
    matches = {} #create empty dictionary
    for i in dna_database[0]: #where is name / AGATC ...
        matches[i] = (longest_match(dna_sequence , i))

    # TODO: Check database for matching profiles
    # go through database 1 line at a time, if a str matches add 1 to counter...
    # if counter is the same as strs length then all strs match row therefore found a match.
    # else, continue for all rows
    suspect = 'No Match'
    match_counter = 1
    for i in range(len(dna_database)):
        for j in matches:
            if str(matches[j]) == dna_database[i][j]:
                match_counter += 1
        if match_counter == len(matches):
            suspect = dna_database[i]['name']
            break
        match_counter = 1

    print(suspect)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
