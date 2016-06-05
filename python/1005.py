import sys

try:
    a = float(raw_input())
    b = float(raw_input())
    sys.stdout.write("MEDIA = "+format((a*3.5+b*7.5)/(3.5+7.5),'.5f'))
except ValueError:
    sys.exit("The number should be float")
