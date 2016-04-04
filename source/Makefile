export CFLAGS

PREFIX = /usr/local
OBJS = lisp4c.o
OUTPUT = lisp4c.a
SRC = lisp4c.c \
	testlisp4c.c
BINARY = testlisp4c
LIBS = -lm -lpthread

all: $(OUTPUT) util

$(OUTPUT): $(OBJS)
	ar rcs $(OUTPUT) $(OBJS)

util: $(UTILS)

.c.o:
	$(CC) -c $*.c
	$(CC) -o $(BINARY) $(SRC)

clean:
	rm -f core *.o $(OUTPUT)$(BINARY)
	rm -f $(UTILS)

install:
	cp *.h $(PREFIX)/include
	cp *.a $(PREFIX)/lib
	cp $(BINARY) $(PREFIX)/bin

wc:
	cat *.c *.h | wc
