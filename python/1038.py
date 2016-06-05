
price = dict()
price[1] = 4.0
price[2] = 4.5
price[3] = 5.0
price[4] = 2.0
price[5] = 1.5

string = raw_input()
code = int(string.split(" ")[0])
quantity = int(string.split(" ")[1])

print "Total: R$", format(quantity*price[code],".2f")
