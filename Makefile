CC = clang
PROGRAM = fft
VERSION = 0.1.0


.PHONY: all clean


IM = src/imaginary
IMS_C = $(IM)/cf32.c $(IM)/cf64.c $(IM)/ci32.c $(IM)/ci64.c
IMS_O = cf32.o cf64.o ci32.o ci64.o

F = src/functions
F_C = $(F)/functions.c
F_O = functions.o

P = src/poly
PS_C = $(P)/poly_f64.c $(P)/poly_cf64.c
PS_O = poly_cf64.o

DFT = src/dft
DFT_C = $(DFT)/dft_cf64.c
DFT_O = dft_cf64.o

ALL_O = $(PS_O) $(F_O) $(IMS_O) $(DFT_O)


all: dft.o

clean:
	rm *.o *.so *.out

imaginary.o:
	$(CC) -c $(IMS_C)

cf32.o:
	$(CC) -c $(IM)/cf32.c

cf64.o:
	$(CC) -c $(IM)/cf64.c

ci32.o:
	$(CC) -c $(IM)/ci32.c

ci64.o:
	$(CC) -c $(IM)/ci64.c

functions.o:
	$(CC) -c $(F_C) $(IMS_C)

poly.o:
	$(CC) -c $(PS_C) $(F_C) $(IMS_C)

dft.o:
	$(CC) -c $(DFT_C) $(PS_C) $(F_C) $(IMS_C)

libfft.a: all
	ar rcs libfft.a $(ALL_O)
