IDIR = ../include
CC = g++ 
# Compiler type 
CFLAGS = -I$(IDIR)
# -I look for current directory
# -I$(IDIR) look for the IDIR directory
OPTION = -std=c++17

ODIR = obj
LDIR = ../lib

LIBS = -lm 
# include system lib like math library here
_DEPS = hellomake.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))
# user patsubst function to substitude all the files in _DEPS
# to name IDIR/origin_filename

_OBJ = hellomake.o hellofunc.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# -c flag generate object file, -o $@ says put the output of 
# compilation in the file named left of :, $< is the first item
# in the dependencies list

hellomake : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
# $@ left side of :, $^ right side of :

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
