# Obtain input
name = input("Enter employee's name: ")

hours = eval(input("Enter number of hours worked in a week: "))
payRate = eval(input("Enter hourly pay rate: "))
fedTaxWithholdingRate = eval(input("Enter federal tax withholding rate: "))
stateTaxWithholdingRate = eval(input("Enter state tax withholding rate: "))

grossPay = hours * payRate
fedTaxWithholding = grossPay * fedTaxWithholdingRate
stateTaxWithholding = grossPay * stateTaxWithholdingRate
totalDeduction = fedTaxWithholding + stateTaxWithholding
netPay = grossPay - totalDeduction

# Obtain output
out = "Employee Name: " + name + "\n\n"
out += "Hours Worked:  " + str(hours) + '\n'
out += "Pay Rate: $" + str(payRate) + '\n'
out += "Gross Pay: $" + str(grossPay) + '\n'
out += "Deductions:\n"
out += "  Federal Withholding (" + str(fedTaxWithholdingRate * 100) + \
    "%): $" + str(int(fedTaxWithholding * 100) / 100.0) + '\n'
out += "  State Withholding (" + str(stateTaxWithholdingRate * 100) + "%):"  + \
    "  $" + str(int(stateTaxWithholding * 100) / 100.0) + '\n';
out += "  Total Deduction:" + "  $" + \
    str(int(totalDeduction * 100) / 100.0) + '\n'
out += "Net Pay:" + "   $" + str(int(netPay * 100) / 100.0)

print(out)
