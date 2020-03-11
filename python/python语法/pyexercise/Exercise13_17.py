import urllib.request
input = urllib.request.urlopen("http://cs.armstrong.edu/liang/data/Salary.txt")

totalAssistant = totalAssociate = totalFull = total = 0
countAssistant = countAssociate = countFull = 0
for line in input:
    items = line.split()
    total += eval(items[3])
    
    if items[2].decode() == "assistant":
        totalAssistant += eval(items[3])
        countAssistant += 1
    elif items[2].decode() == "associate":
        totalAssociate += eval(items[3])
        countAssociate += 1
    else:
        if items[2].decode() == "full":
            totalFull += eval(items[3])
            countFull += 1

print("Total salary for assistant professors: ", format(totalAssistant, ".2f"))
print("Total salary for associate professors: ", format(totalAssociate, ".2f"))
print("Total salary for full professors: ", format(totalFull, ".2f"))
print("Average salary for assistant professors: ", format(totalAssistant / countAssistant, ".2f"))
print("Average salary for associate professors: ", format(totalAssociate / countAssociate, ".2f"))
print("Average salary for full professors: ", format(totalFull / countFull, ".2f"))
