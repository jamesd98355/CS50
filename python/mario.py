# TODO

height = 0
while height < 1 or height > 8:
    height = int(input("Enter height of pyramid (1-8): "))

for i in range(height):
    print(" " * (height - i) + ("#" * (i+1)))



