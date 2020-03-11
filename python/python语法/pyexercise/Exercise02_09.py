# Prompt the user to enter a degree in Celsius
fahrenheit = eval(input("Enter the temperature in Fahrenheit between -58 and 41: "))
    
# Enter the wind speed miles per hour
speed = eval(input("Enter the wind speed miles per hour " + 
    "(must be greater than or equal to 2): "))
    
# Compute wind chill index
windChillIndex = 35.74 + 0.6215 * fahrenheit - 35.75 * speed ** 0.16 + \
    0.4275 * fahrenheit * speed ** 0.16
      
# Display the result
print("The wind chill index is", windChillIndex)
