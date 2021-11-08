from complex import Complex
from polar import Polar
from fraction import Fraction
import random


def input_from_file(number_data: list):
    number_type = int(number_data[0])
    if number_type == 1:
        return Complex(*number_data[1:])
    elif number_type == 2:
        return Fraction(*number_data[1:])
    elif number_type == 3:
        return Polar(*number_data[1:])
    else:
        print("Unknown number type")


def input_random():
    number_type = random.choice([0, 1, 2])
    if number_type == 0:
        return Complex()
    elif number_type == 1:
        return Fraction()
    else:
        return Polar()
