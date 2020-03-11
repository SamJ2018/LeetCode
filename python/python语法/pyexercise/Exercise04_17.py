import random

# Generate scissor, rock, paper
computerNumber = random.randint(0, 2)

# Prompt the user to enter scissor, rock, or paper
userNumber = eval(input("scissor (0), rock (1), paper (2): "))

# Check the guess
if computerNumber == 0:
    if userNumber == 0:
        print("The computer is scissor. You are scissor too. It is a draw")
    elif userNumber == 1:
        print("The computer is scissor. You are rock. You won")
    elif userNumber == 2:
        print("The computer is scissor. You are paper. You lost")
elif computerNumber == 1:
    if userNumber == 0:
        print("The computer is rock. You are scissor. You lost")
    elif userNumber == 1:
        print("The computer is rock. You are rock too. It is a draw")
    elif userNumber == 2:
        print("The computer is rock. You are paper. You won")
elif computerNumber == 2:
    if userNumber == 0:
        print("The computer is paper. You are scissor. You won")
    elif userNumber == 1:
        print("The computer is paper. You are rock. You lost")
    elif userNumber == 2:
        print("The computer is paper. You are paper too. It is a draw")
