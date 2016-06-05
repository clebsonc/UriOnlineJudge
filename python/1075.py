a = int(raw_input())
values = [x for x in range(1, 10001, 1) if x % a == 2]
for val in values:
    print str(val)
