a = int(raw_input())
values = list()
for i in range(a):
    values.append(int(raw_input()))

print str(len([x for x in values if x >= 10 and x <= 20])), 'in'
print str(len([x for x in values if x < 10 or x > 20])), 'out'
