IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = daiCy.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = dcarray_test.o daiCy.o
_OBJ2 = dcstring_test.o daiCy.o
_OBJ3 = dcfarray_test.o daiCy.o
_OBJ4 = dcstack_test.o daiCy.o
_OBJ5 = dcqueue_test.o daiCy.o
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))
OBJ3 = $(patsubst %,$(ODIR)/%,$(_OBJ3))
OBJ4 = $(patsubst %,$(ODIR)/%,$(_OBJ4))
OBJ5 = $(patsubst %,$(ODIR)/%,$(_OBJ5))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~


