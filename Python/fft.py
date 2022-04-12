import math
import itertools
from typing import List, Union, Callable


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


def fft(poly: List[T]) -> List[T]:
    n = len(poly)
    if n == 1 or n == 0:
        return poly

    assert n % 2 == 0, f'len(poly) == {n}'
    even = [poly[i] for i in range(0, n, 2)]
    odd = [poly[i] for i in range(1, n, 2)]
    
    even = fft(even)
    odd = fft(odd)
    
    w: complex = math.e**(-2j * math.pi/n)
    ws: List[complex] = [w**i for i in range(len(even))]
 
    left = (even[i] + odd[i] * w for (i, w) in enumerate(ws))
    right = (even[i] - odd[i] * w for (i, w) in enumerate(ws))

    return [coeff for coeff in itertools.chain(left, right)]


def ifft(poly: List[T]) -> List[T]:
    n = len(poly)
    if n == 1 or n == 0:
        return poly

    f = fft(poly)
    inv = itertools.chain([f[0]], reversed(f[1:]))
    return [x/n for x in inv]

