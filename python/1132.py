a = int(raw_input())
b = int(raw_input())
if a < b: 
    print sum([x for x in range(a, b+1, 1) if x%13 !=0])
else:
    print sum([x for x in range(b, a+1, 1) if x%13 != 0])
