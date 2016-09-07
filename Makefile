
CFLAGS+=-O
CFLAGS+=-Wall -Werror
#CFLAGS+=-Wno-unused-function

LDFLAGS+=-lm

.PHONY: all clean world

all:: Assign4

Assign4: Assign4.o queue.o process.o
	$(LINK.cpp) -o $@ $^

clean::
	rm -f *.o Assign4

world:: clean all

Assign4.o:: Assign4.cpp queue.h Assign4.h process.h
queue.cpp:: queue.h
process.cpp:: process.h


