import random

def main():   
    for N in range(10, 80 + 1):
        # Run simulation 10000 times
        count = 0
        for k in range(10000):
            if not getAPath(N):
                count += 1

        print("For lattice of size " + str(N) + ", the probability of dead-end paths is " + str((count / 10000.0) * 100) + "%")
  
def getAPath(N):   
    # Refresh lattice
    lattice = []
    for k in range(N + 1):
        lattice.append((N + 1) * [False])

    # Reset i, j to the center of the lattice
    i = (N + 1) // 2  
    j = (N + 1) // 2 

    while i > 0 and i < N and j > 0 and j < N:
        if lattice[i - 1][j] and lattice[i + 1][j] and \
            lattice[i][j - 1] and lattice[i][j + 1]:
            return False # Dead end

        r = random.random()
        if r < .25 and not lattice[i][j + 1]:
            lattice[i][j] = True # Right
            j += 1
        elif r < .50 and not lattice[i + 1][j]:
            lattice[i][j] = True # Down
            i += 1
        elif r < .75 and not lattice[i][j - 1]:
            lattice[i][j] = True # Left
            j -= 1
        elif r < 1.00 and not lattice[i - 1][j]:
            lattice[i][j] = True # Up
            i -= 1

    return True

main()
