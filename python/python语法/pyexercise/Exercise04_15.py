import random

# Generate a lottery
lottery = random.randint(0, 999)

# Prompt the user to enter a guess
guess = eval(input("Enter your lottery pick (three digits): "))

# Get digits
l1 = lottery // 100;
l2 = (lottery % 100) // 10; # l2 = (lottery / 10) % 10
l3 = lottery % 10;

g1 = guess // 100
g2 = (guess % 100) // 10
g3 = guess % 10

print("Lottery is " + str(lottery))
    
# Check the guess
if guess == lottery:
    print("Exact match: you win $10,000")
elif g1 == l1 and g3 == l2 and g2 == l3 or \
        g2 == l1 and g1 == l2 and g3 == l3 or \
        g2 == l1 and g3 == l2 and g1 == l3 or \
        g3 == l1 and g1 == l2 and g2 == l3 or \
        g3 == l1 and g2 == l2 and g1 == l3:
    print("Match all digits: you win $3,000")
elif g1 == l1 or g1 == l2 or g1 == l3 or \
        g2 == l1 or g2 == l2 or g2 == l3 or \
        g3 == l1 or g3 == l2 or g3 == l3:
    print("Match one digit: you win $1,000")
else:
    print("Sorry, no match")
