a = int(raw_input())
b = int(raw_input())
if a < b:
    print str(sum([x for x in range(a+1, b, 1) if x % 2 != 0]))
else:
    print str(sum([x for x in range(b+1, a, 1) if x % 2 != 0]))
    
