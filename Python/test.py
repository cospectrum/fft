import random
import numpy as np
from fft import *


def random_poly(deg: int, max_value = 10, integer: bool = True) -> list:
    if integer:
        return [random.randint(-max_value, max_value) for _ in range(deg+1)]
    return [random.uniform(-max_value, max_value) for _ in range(deg+1)]


def d(p1, p2):
    return sum(abs(x-y) for (x, y) in zip(p1, p2))


def test_dft(epsilon=0.5):
    for deg in range(1, 10):
        poly = random_poly(deg)
        distance = d(dft(poly), np.fft.fft(poly))
        assert distance < epsilon, f'deg={deg}; distance={distance}'
    
    return


def test_fft(epsilon=0.5):
    for _ in range(10):
        deg = 2**random.randint(0, 5)
        poly = random_poly(deg-1)
        
        distance = d(dft(poly), fft(poly))
        assert distance < epsilon, f'deg={deg}; distance={distance}'
    
    return


if __name__ == '__main__':
    test_fft()
    test_dft()
    print('success!')

