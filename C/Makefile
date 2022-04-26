CC = clang
PROGRAM = fft
VERSION = 0.1.0


.PHONY: all clean 


IM = src/imaginary
IMS = $(IM)/cf32.c $(IM)/cf64.c $(IM)/ci32.c $(IM)/ci64.c
IMS_O = cf32.o cf64.o ci32.o ci64.o

F = src/functions/functions.c
F_O = functions.o

P = src/poly/poly_
PS = $(P)f64.c $(P)cf64.c
PS_O = poly_cf64.o

DFT = src/dft/dft_
DFTS = $(DFT)cf64.c
DFTS_O = dft_cf64.o

ALL_O = $(PS_O) $(F_O) $(IMS_O) $(DFTS_O)


all: dft.o

clean:
	rm *.o *.so *.out

imaginary.o:
	$(CC) -c $(IMS)

cf32.o:
	$(CC) -c $(IM)/cf32.c

cf64.o:
	$(CC) -c $(IM)/cf64.c

ci32.o:
	$(CC) -c $(IM)/ci32.c

ci64.o:
	$(CC) -c $(IM)/ci64.c

functions.o: imaginary.o
	$(CC) -c $(F)

poly.o: imaginary.o
	$(CC) -c $(PS)

dft.o: imaginary.o
	$(CC) -c $(DFTS) $(PS) $(F)

libfft.a: all
	ar rcs libfft.a $(ALL_O)
