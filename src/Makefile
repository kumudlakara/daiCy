CC=gcc
IDIR = ../include
CFLAGS=-I$(IDIR)

ODIR = obj/
LDIR = ../lib
TDIR = test/

LIBS = -lm

_DEPS = daiCy.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_OBJ = dcarray.o dcfarray.o dcstring.o dcstack.o dcqueue.o
#OBJ = $(patsubst %,$(ODIR)%,$(_OBJ))

testf: $(TDIR)dcstring_test.c daiCy.so
	$(CC) -o $@ $(CFLAGS) $< daiCy.so
daiCy.so: dcarray.o dcfarray.o dcstring.o dcstack.o dcqueue.o
	ar crv $@ obj/dcarray.o obj/dcfarray.o obj/dcstring.o obj/dcstack.o obj/dcqueue.o obj/dcmatrix.o
#	mv $@ $(LDIR)
dcarray.o: dcarray.c $(DEPS)
	$(CC) -c $(CFLAGS) $< 
	mv $@ $(ODIR)

dcfarray.o: dcfarray.c $(DEPS)
	$(CC) -c $< $(CFLAGS)
	mv $@ $(ODIR)

dcstring.o: dcstring.c $(DEPS)
	$(CC) -c $(CFLAGS) $< 
	mv $@ $(ODIR)

dcstack.o: dcstack.c $(DEPS)
	$(CC) -c $(CFLAGS) $< 
	mv $@ $(ODIR)

dcqueue.o: dcqueue.c $(DEPS)
	$(CC) -c $(CFLAGS) $< 
	mv $@ $(ODIR)

dcmatrix.o: dcmatrix.c $(DEPS)
	$(CC) -c $(CFLAGS) $< 
	mv $@ $(ODIR)

clean: 
	rm -f $(ODIR)/*.o 
