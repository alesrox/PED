.PHONY= doc clean

CC=g++
OPTIONS= -g
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tporo.o tvectorporo.o tlistaporo.o 
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tad: src/tad.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o tad

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

doc:
	doxygen

tar: clean
	tar -czvf PRACTICA.tgz *

clean:
	rm -f $(OBJ)
	rm -r -f *.o *.dSYM tad PRACTICA.tgz
