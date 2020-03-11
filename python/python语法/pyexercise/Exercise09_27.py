from tkinter import * # Import tkinter
    
def getMonthlyPayment(loanAmount, numberOfYears, monthlyInterestRate):
    return loanAmount * monthlyInterestRate / (1
        - 1 / (1 + monthlyInterestRate) ** (numberOfYears * 12))

class MainGUI:
    def __init__(self):        
        window = Tk() # Create a window
        window.title("Compare Interest Rates") # Set title
        
        frame1 = Frame(window)
        frame1.pack()
        
        Label(frame1, text = "Loan Amount").grid(row = 1, 
            column = 1, sticky = W)
        
        self.loanAmount = StringVar()
        Entry(frame1, textvariable = self.loanAmount, 
            justify = RIGHT).grid(row = 1, column = 2)
        Label(frame1, text = "Years").grid(row = 1, 
            column = 3, padx = 5)
        self.numberOfYears = StringVar()
        Entry(frame1, textvariable = self.numberOfYears, 
            justify = RIGHT).grid(row = 1, column = 4)
        Button(frame1, text = "Calculate", 
            command = self.computeFutureValue).grid(row = 1, column = 5, sticky = E)
        
        frame2 = Frame(window)
        frame2.pack()
        scrollbar = Scrollbar(frame2)
        scrollbar.pack(side = RIGHT, fill = Y)
        self.text = Text(frame2, wrap = WORD, yscrollcommand = scrollbar.set)
        self.text.pack()
        scrollbar.config(command = self.text.yview)
        
        window.mainloop() # Create an event loop

    def computeFutureValue(self):
        loan = float(self.loanAmount.get())
        years = int(self.numberOfYears.get())
            
        self.text.insert(END, "{0:20s}{1:20s}{2:20s}\n".format("Interest Rate", "Monthly Payment", "Total Payment"))
                    
        annualInterestRate = 5
        while annualInterestRate <= 8:
            monthlyPayment = getMonthlyPayment(loan, years, annualInterestRate / 1200)
            totalPayment = monthlyPayment * years * 12
            self.text.insert(END, "{0:<20.2f}{1:<20.2f}{2:<20.2f}\n".format(annualInterestRate, monthlyPayment, totalPayment))
            annualInterestRate += 1 / 8

MainGUI()
