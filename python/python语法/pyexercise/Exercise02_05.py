subtotal, rate = eval(input("Enter subtotal and gratuity rate: "))

gratuity = subtotal * rate / 100
total = subtotal + gratuity

print("The gratuity is", int(gratuity * 100) / 100, 
      "and total is", int(total * 100) / 100)
