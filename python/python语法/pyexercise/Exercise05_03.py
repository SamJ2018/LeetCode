print(format("Kilograms", "<15s"), format("Pounds", ">10s"))
print("-------------------------------------")

kilograms = 1
while kilograms < 200:
    print(format(kilograms, "<15d"), format(kilograms * 2.2, ">10.1f"))
    kilograms += 2
