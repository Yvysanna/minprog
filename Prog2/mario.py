from cs50 import get_int

# Take starting value outside of index
height = -1

# Loop until valid argument is given
while height < 0 or height > 23:
    height = get_int("Height: ")

for i in range(height):
    print(" " * ((height - i) - 1), end='')
    print("#" * (height - (height - i) + 2))
