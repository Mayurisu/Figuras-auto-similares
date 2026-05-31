CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
LDLIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

SRC = turtlec.c
PROGRAMS = fractalTree fractalTreeVar curvaLevy reto1 testLine

all: $(PROGRAMS)

fractalTree: fractalTree.c $(SRC) turtlec.h
	$(CC) $(CFLAGS) $(SRC) fractalTree.c -o fractalTree $(LDLIBS)

fractalTreeVar: fractalTreeVar.c $(SRC) turtlec.h
	$(CC) $(CFLAGS) $(SRC) fractalTreeVar.c -o fractalTreeVar $(LDLIBS)

curvaLevy: curvaLevy.c $(SRC) turtlec.h
	$(CC) $(CFLAGS) $(SRC) curvaLevy.c -o curvaLevy $(LDLIBS)

reto1: reto1.c $(SRC) turtlec.h
	$(CC) $(CFLAGS) $(SRC) reto1.c -o reto1 $(LDLIBS)

testLine: testLine.c $(SRC) turtlec.h
	$(CC) $(CFLAGS) $(SRC) testLine.c -o testLine $(LDLIBS)

clean:
	rm -f $(PROGRAMS)
