s = int(raw_input())
count = 0
while count < 6:
    if s%2 != 0:
        print s
        count += 1
    s += 1
