## Usage

```python
from fft.recursive import fft, ifft

# 1 + 2x + 3x^2 + 4x^3
poly = [1, 2, 3, 4]

ft = fft(poly)
inverse_ft = ifft(poly)

```
