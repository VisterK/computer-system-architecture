from number import Number
import random


class Polar(Number):

    def __init__(self, *args):
        self.__phi = 0
        self.__r = 0
        if len(args) == 0:
            self._input_random()
        else:
            self._input_from_file(*args)

    def _input_random(self):
        self.__phi = random.randint(0, 1000)
        self.__r = random.randint(0, 1000)

    def _input_from_file(self, a, b):
        self.__phi = float(a)
        self.__r = float(b)

    def _convert_to_real(self) -> float:
        return self.__r

    def __str__(self):
        return """This is a polar number:
              Angle: {0}
              Radius: {1}
              Converted to real: {2}\n""".format(self.__phi, self.__r, self._convert_to_real())
