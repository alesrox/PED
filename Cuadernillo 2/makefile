.PHONY= doc clean

CC=g++
OPTIONS= -g
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tporo.o  tabbporo.o tvectorporo.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tad:    src/tad.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o tad

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

tar:
	tar cvzf practica.tgz ./*.* src include lib

doc:
	doxygen

clean:
	rm -f $(OBJ) ./tad practica.tgz tad.dSYM
