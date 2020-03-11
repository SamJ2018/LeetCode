def main():
    print(format("Feet", "<15s"), format("Meters", "<15s"), " |    ", 
        format("Meters", "<15s"), format("Feet", "<15s"))
    print("--------------------------------------------------------------------")

    foot = 1
    meter = 20
    i = 1
    while i <= 10:
      print(format(foot, "<15d"), format(footToMeter(foot), "<15.3f"), " |    ", 
          format(meter, "<15d"), format(meterToFoot(meter), "<15.2f"))
      foot += 1
      meter += 5
      i += 1

# Converts from feet to meters 
def footToMeter(foot):
    return 0.305 * foot

# Converts from meters to feet 
def meterToFoot(meter):
    return (1 / 0.305) * meter

main()
