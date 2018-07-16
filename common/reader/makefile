files = csv.cpp csv_test.cpp

IDIR=.
ODIR=.

_DEPS= csv.h
DEPS=$(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ=csv.cpp csv_test.cpp
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

CC=g++
CFLAGS = -I.
OPTION=-std=c++17

main : $(_OBJ)
	$(CC) $(OPTION) -o $@ $^ $(CFLAGS)

.PHONY:clean
	clean:
	-rm edit $(files)