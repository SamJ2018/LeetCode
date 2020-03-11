def main():
    deck = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
    
    count = 0;
    for i1 in range(len(deck)): 
      for i2 in range(i1 + 1, len(deck)):
        for i3 in range(i2 + 1, len(deck)):
          for i4 in range(i3 + 1, len(deck)):
            a = deck[i1]
            b = deck[i2]
            c = deck[i3]
            d = deck[i4]

            if a + b + c + d == 24:
              count += 1
    
    print("The number of picks that yields the sum of 24 is", count)

main()
