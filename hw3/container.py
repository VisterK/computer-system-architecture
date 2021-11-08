from number import Number
from input import *


class Container:
    def __init__(self, size="-1", filename=None, type='f'):
        self.__size = int(size)
        self.__filename = filename
        self.__cont = []
        self.__type = type

    def fill(self):
        if self.__type == 'f':
            with open(self.__filename, 'r') as file:
                data = file.readlines()
                self.__size = len(data)
                self.__cont = [input_from_file(line.split(' ')) for line in data]
        else:
            self.__cont = [input_random() for _ in range(self.__size)]

    def print(self, filename):
        with open(filename, 'w') as out:
            for number in self.__cont:
                out.write(str(number))

    def sort(self):
        i = 0
        while i < len(self.__cont):
            k = i
            for j in range(i + 1, len(self.__cont)):
                if self.__cont[j]._convert_to_real() > self.__cont[k]._convert_to_real():
                    k = j
            self.__cont[i], self.__cont[k] = self.__cont[k], self.__cont[i]
            i += 1
