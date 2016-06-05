string = raw_input().split(" ")
for idx in range(0, len(string), 1):
    string[idx] = float(string[idx])


string = sorted(string, reverse=True)

if string[0] >= (string[1] + string[2]):
    print "NAO FORMA TRIANGULO"
else:
    if string[0]**2 == (string[1]**2 + string[2]**2):
        print "TRIANGULO RETANGULO"
    if string[0]**2 > (string[1]**2 + string[2]**2):
        print "TRIANGULO OBTUSANGULO"
    if string[0]**2 < (string[1]**2 + string[2]**2):
        print "TRIANGULO ACUTANGULO"
    if string[0] == string[1] == string[2]:
        print "TRIANGULO EQUILATERO"
    if string[0] == string[1] != string[2] \
        or string[0] == string[2] != string[1] \
        or string[1] == string[2] != string[0]:
        print "TRIANGULO ISOSCELES"
