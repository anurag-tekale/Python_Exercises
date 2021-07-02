# FUNCTIONS

# This one is like your scripts using argv

def print_two(*args):
    arg1, arg2 = args
    print(f"arg1: {arg1}, arg2 : {arg2}")

    # *args is pointless we can do this way

def print_two_again(arg1, arg2):
    print(f"arg1: {arg1}, arg2 : {arg2} ")


    # This just takes one argument

def print_one(arg1):
    print(f"arg1: {arg1}")

    # This print nothing

def print_none():
    print("I got nothi'. ")

print_two("Zed", "Shaw")
print_two_again("Zed", "Shaw")
print_one("First")
print_none()