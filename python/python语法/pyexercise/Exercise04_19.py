# Enter three edges
    
edge1, edge2, edge3 = eval(input("Enter three edges (length in double): "))

# Display results
valid = (edge1 + edge2 > edge3) and \
      (edge1 + edge3 > edge2) and (edge2 + edge3 > edge1)

# Display results
print("Can edges " + str(edge1) + ", " +
    str(edge2) + ", and " + str(edge3) + " form a triangle? " + str(valid))
