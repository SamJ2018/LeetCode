tuition = 10000
count = 1
while count <= 10:
    tuition = tuition * 1.05;
    count += 1
    
print("Tuition in ten years is", tuition)

sum = tuition
for i in range(2, 5):
    tuition = tuition * 1.05
    sum += tuition
    
print("The four-year tuition in ten years is", sum)
