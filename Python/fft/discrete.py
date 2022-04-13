import math
from typing import List, Union

T = Union[int, float, complex]


def dft(poly: List[T]) -> List[T]:
    N = len(poly)
    if N == 1 or N == 0:
        return poly

    w: complex = math.e ** (-2j * math.pi/N)    
    result = [
        sum(poly[n] * (w**k)**n for n in range(N))
        for k in range(N)
    ]
    return result


def idft(poly: List[T]) -> List[T]:
    N = len(poly)
    if N == 1 or N == 0:
        return poly

    w: complex = math.e ** (2j * math.pi/N)
    result = [
        sum(poly[k] * (w**n)**k for k in range(N)) / N
        for n in range(N)
    ]
    return result

