v = list()
for i in range(100):
    v.append(int(raw_input().strip()))
print max(v)
print (v.index(max(v))+1)
