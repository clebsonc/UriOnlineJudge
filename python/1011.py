class Sphere(object):
    def __init__(self, radius):
        self.PI = 3.14159
        self.radius = radius
    
    def volume(self):
        return 4./3. * self.PI * self.radius**3

if __name__ == '__main__':
    try:
        r = int(raw_input())
        a = Sphere(r)
        print "VOLUME = "+format(a.volume(),".3f")
    except ValueError:
        print "Error while parsing"
