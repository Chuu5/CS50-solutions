# TODO
from cs50 import get_int

while True:
    height = get_int("Height: ")

    if height <= 8 and height > 0:
        break


for i in range(height):

    # printing the spaces
    for h in range(height - 1 - i):
        print(" ", end="")

    # printing the hashes
    for j in range(i + 1):
        print("#", end="")

    print()