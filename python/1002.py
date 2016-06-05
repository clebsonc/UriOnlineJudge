import sys
pi = 3.14159
try:
    r = float(raw_input())
except ValueError:
    print "Invalid Number"
sys.stdout.write('A='+format(pi*r**2, '.4f')+'\n')
