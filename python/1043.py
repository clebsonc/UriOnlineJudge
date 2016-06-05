valores = raw_input()
a, b, c = valores.split(" ")
a = float(a)
b = float(b)
c = float(c)

if (abs(b - c) < a < (b+c)) and (abs(a-c) < b < (a+c)) and (abs(a-b) < c < (a+b)):
    print "Perimetro = "+format((a+b+c),".1f")
else:
    print "Area = "+format((a+b)/2*c, '.1f')
