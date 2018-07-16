IDIR=../../common/reader
# head file directory
ODIR=../../common/reader
# cpp file directory
_DEPS= csv.h
# head file name
_OBJ=csv.cpp
# cpp file names
_OBJ2=data_loader.cpp

CC=g++
# Compiler type 
CFLAGS =-I.
# -I look for current directory
# -I$(IDIR) look for the IDIR directory
OPTION=-std=c++17


DEPS=$(patsubst %, $(IDIR)/%, $(_DEPS))
# user patsubst function to substitude all the files in _DEPS
# to name IDIR/origin_filename

OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))
OBJ2 = $(_OBJ2)

$(ODIR)/%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# -c flag generate object file, -o $@ says put the output of 
# compilation in the file named left of :, $< is the first item
# in the dependencies list

main : $(OBJ) $(OBJ2)
	$(CC) $(OPTION) -o $@ $^ $(CFLAGS)
# $@ left side of :, $^ right side of :

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
