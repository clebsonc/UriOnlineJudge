# -*- coding: utf-8 -*-

import sys

class Salary(object):
    def __init__(self, id_number, hours, value_hour):
        self.number = id_number
        self.hours = hours
        self.value_hour = value_hour
    
    def getNumber(self):
        return self.number

    def getSalary(self):
        return self.hours * self.value_hour

if __name__ == "__main__":
    try:
        number = int(raw_input())
        hours = int(raw_input())
        value_hour = float(raw_input())
        a = Salary(id_number = number, hours = hours, value_hour = value_hour)
        sys.stdout.write("NUMBER = "+str(a.getNumber()) + "\nSALARY = U$ "+format(a.getSalary(),'.2f') + "\n")
    except ValueError:
        sys.exit("Invalid Number Given")
