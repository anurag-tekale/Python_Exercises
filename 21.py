# Exercise 32 - Loops and Lists

the_count = [1, 2, 3 , 4, 5]
fruits = ['apples', 'oranges', 'pears', 'apricots']
change = [1, 'pennies', 2, 'dimes', 3, 'quarters']

# This first kind of for-loop goes through list
for number in the_count :
    print(f"This is the count {number}")

for fruit in fruits :
    print(f"A fruit of type : {fruit}")

# Also we can go through mixed lists also
# Notice that we have to use {} since we don't know what's in

for i in change:
    print(f"I got {i}")

# We can also build lists, start with empty one
elements = []

# Then use the range function to do 0 to 5 counts
for i in range(0, 6):
    print(f"Adding {i} to the list.")
    # Append is the function that lists understand
    elements.append(i)

# Now we can print them too
for i in elements:
    print(f"Element was : {i}")