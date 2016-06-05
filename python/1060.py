values = list()
for i in range(5):
    values.append(float(raw_input()))

cp = 0
cn = 0
ce = 0
co = 0
for v in values:
    if v > 0:
        cp += 1
    elif v<0:
        cn += 1
    if v % 2 == 0:
        ce += 1
    else:
        co += 1;

print ce, "valor(es) par(es)"
print co, "valor(es) impar(es)"
print cp, "valor(es) positivo(s)"
print cn, "valor(es) negativo(s)"
