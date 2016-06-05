a, b, c = raw_input().split(" ")
a, b, c = float(a), float(b), float(c)
while a!=0:
    pag = int(b / ( c - a) * a * c)
    if pag != 1:
        print str(pag), "paginas"
    else:
        print str(pag), "pagina"
    
    string = raw_input().split(" ")
    if len(string) != 1:
        a, b, c = float(string[0]), float(string[1]), float(string[2])
    else:
        a = int(string[0])

