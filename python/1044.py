buf = raw_input().split(" ")
for i in range(0, len(buf), 1):
    buf[i] = float(buf[i])
if (max(buf) % min(buf) ) == 0:
    print "Sao Multiplos"
else:
    print "Nao sao Multiplos"
