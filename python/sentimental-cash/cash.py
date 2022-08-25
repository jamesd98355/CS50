# TODO
# program that calculates the minimum coins needed to give change back to an individual
from cs50 import get_float
import math

amount = -1
coins_needed = 0

while amount < 0:
    amount = get_float("Amount owed: ")



# coins available: 25c, 10c, 5c, 1c
#round to 2sf because for example 0.15%0.1 is 0.49999999 for some reason

if (amount >= 0.25):
    coins_needed += math.floor(amount/0.25)
    amount = amount%0.25
    amount = round(amount, 2)
if (amount >= 0.10):
    coins_needed += math.floor(amount/0.10)
    amount = amount%0.10
    amount = round(amount, 2)
if (amount >= 0.05):
    coins_needed += math.floor(amount/0.05)
    amount = amount%0.05
    amount = round(amount, 2)
if (amount >= 0.01):
    coins_needed += math.floor(amount/0.01)
    amount = amount%0.01

print(int(coins_needed))