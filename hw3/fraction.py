from number import Number
import random


class Fraction(Number):

    def __init__(self, *args):
        self.__a = 0
        self.__b = 1
        if len(args) == 0:
            self._input_random()
        else:
            self._input_from_file(*args)

    def _input_random(self):
        self.__a = random.randint(0, 1000)
        self.__b = random.randint(1, 1000)

    def _input_from_file(self, a, b):
        self.__a = int(a)
        self.__b = int(b)

    def _convert_to_real(self) -> float:
        return self.__a / self.__b

    def __str__(self):
        return """This is a fraction number:
              Numerator: {0}
              Denominator: {1}
              Converted to real: {2}\n""".format(self.__a, self.__b, self._convert_to_real())
