def main():
    numberOfCities = eval(input("Enter the number of cities: "))
    
    line = input("Enter the coordinates of the cities: ").split()
    cities = [ [eval(line[i]), eval(line[i + 1])] for i in range(0, 2 * numberOfCities, 2) ]
        
    minTotal = totalDistance(cities, 0)
    minIndex = 0
    for i in range(1, len(cities)):
        total = totalDistance(cities, i)
      
        if minTotal > total:
            minTotal = total
            minIndex = i
    
    print("The central city is at (" +
        str(cities[minIndex][0]) + ", " + str(cities[minIndex][1]) + ")")
  
def totalDistance(cities, i):
    total = 0
    for j in range(len(cities)): 
        total += distance(cities[i], cities[j])
    return total
  
def distance(c1, c2):
    return ((c1[0] - c2[0]) * (c1[0] - c2[0]) +
      (c1[1] - c2[1]) * (c1[1] - c2[1])) ** 0.5

main()
