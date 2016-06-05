import numpy as np

buf = raw_input()
a = float(buf.split(" ")[0])
b = float(buf.split(" ")[1])
c = float(buf.split(" ")[2])

delta = (b**2)-(4*a*c)
if delta < 0 or a == 0.0:
    print "Impossivel calcular"
else:
    x1 = (-b + np.sqrt(delta))/(2*a)
    x2 = (-b - np.sqrt(delta))/(2*a)
    print "R1 =", format(x1,".5f")
    print "R2 =", format(x2,".5f")
