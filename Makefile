CC          := g++
CFLAGS      := -O -std=c++11 -Iinclude
CLIBS       := -lsimple_tokenizer

OBJ := src/lexical.o src/main.o

prefix	    := /usr/local

%.o: %.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

all: bin/fsa_compiler

bin/fsa_compiler: $(OBJ)
	$(CC) -o $@ $^ $(CLIBS)
	make clean_obj

.PHONY: clean install

clean:
	rm -f src/*.o bin/*

clean_obj:
	rm -f src/*.o
	
install: all bin/libsimple_tokenizer.a include/simple_tokenizer.h
	#test -d $(prefix) || mkdir $(prefix)
	#test -d $(prefix)/lib || mkdir $(prefix)/lib
	#test -d $(prefix)/include || mkdir $(prefix)/include
	#test -d $(prefix)/include/simple_tokenizer || mkdir $(prefix)/include/simple_tokenizer
	#install -m 0755 bin/libsimple_tokenizer.a $(prefix)/lib
	#install -m 0755 include/simple_tokenizer.h $(prefix)/include/simple_tokenizer/
