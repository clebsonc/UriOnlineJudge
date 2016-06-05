a = int(raw_input())
a = [x for x in range(1, a+1, 1) if x%2 == 0]
for x in a:
    print str(x)+'^2 = '+str(x**2)
