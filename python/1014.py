# -*- coding: utf-8 -*-

import sys

class Car:
    def __init__(self, km = 1, liters=1):
        self.__km = km
        self.liters = liters

    def setKm(self, km = 1):
        self.__km = km if km >= 0 else 1

    def setLiter(self, liters = 1):
        self.__liters = liter if liter >=0 else 1

    def getLiter(self):
        return self.__liters

    def getKm(self):
        return self.__km

    def computeAverageConsumption(self):
        return self.__km/self.liters

if __name__ == '__main__':
    try:
        a = int(raw_input())
        b = float(raw_input())
        car = Car(km=a, liters=b)
        sys.stdout.write(format(car.computeAverageConsumption(),'.3f') + ' km/l\n')
    except ValueError:
        sys.stdout.write("Error while parsing. ")
        sys.exit(1)
        
