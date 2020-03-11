# Prompt the user to enter weight in pounds
weight = eval(input("Enter weight in pounds: "))

# Prompt the user to enter height in inches
height = eval(input("Enter height in inches: "))

bmi = weight * 0.45359237 / (height * 0.0254 * height * 0.0254)
    
print("BMI is", bmi)
