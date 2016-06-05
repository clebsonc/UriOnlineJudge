a = int(raw_input())
v = list()
for i in range(a):
    v.append(int(raw_input()))
for value in v:
    if value % 2 == 0:
        if value > 0:
            print 'EVEN POSITIVE'
        elif value < 0:
            print 'EVEN NEGATIVE'
        else:
            print 'NULL'
    else:
        if value > 0:
            print 'ODD POSITIVE'
        else:
            print 'ODD NEGATIVE'
        
