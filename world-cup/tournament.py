# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    


    teams = []
    # TODO: Read teams into memory from file



    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            row['rating'] = int(row['rating'])
            teams.append(row)


    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for x in range(N):
        winning_team = simulate_tournament(teams)
        if not winning_team in counts:
            #not already in counts
            counts[winning_team] = 1
        else:
            #add 1 to winning teams score
            counts[winning_team] += 1
        



    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO

    #simulate_round will return half the teams recieved as input
    #repeate simulate_round until returns 1 team

    simulate_round_output = teams

    while len(simulate_round_output) > 1:
        simulate_round_output = simulate_round(simulate_round_output)
    
    #return the team name of the first element in simulate_round_output
    return simulate_round_output[0]["team"]


if __name__ == "__main__":
    main()
