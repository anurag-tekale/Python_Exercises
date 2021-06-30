# Parameters, Unpacking, Variables

from sys import argv

script, first, second, third = argv

print("The script is called :", script)
print("Your first variable is :", first)
print("Your second variable is :", second)
print("Your third variable is :", third)


# What is the difference between argv and input()

# The difference has to do with where the user is required to give input. If they give your script inputs on command line then use argv and If
# you want them to give input using keyboard use input()

