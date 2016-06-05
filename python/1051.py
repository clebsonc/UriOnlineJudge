from math import ceil

def computeTaxes(salary):
    taxes = 0
    left = 0.0
    if salary > 4500.0:
        left = salary - 4500.01
        taxes += left * 0.28
        salary -= left
    if salary > 3000.01:
        left = salary - 3000.01
        taxes += left * 0.18
        salary -= left
    if salary > 2000.01:
        left = salary - 2000.01
        taxes += left * 0.08
        salary -= left
    if salary <= 2000.0:
        print "Isento"
        return
    print "R$ %.2f" %(taxes);


try:
    salary = float(raw_input());
except ValueError as ve:
    print "Error: ", ve
else:
    computeTaxes(salary=salary)
