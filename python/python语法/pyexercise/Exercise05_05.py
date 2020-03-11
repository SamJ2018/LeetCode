print(format("kilograms", "<15s"), format("pounds", ">10s"),
      "              |                ", format("pounds", "<15s"), format("kilograms", ">10s"))
print("---------------------------------------------------------------------------------------")

kilograms = 1
pounds = 20
count = 1
while count <= 100:
    print(format(kilograms, "<15d"), format(kilograms * 2.2, "10.1f"), 
        "              |                ", format(pounds, "<15d"), format(pounds / 2.2, "10.2f"))
    kilograms += 2
    pounds += 5
    count += 1
