CC = gcc
CFLAGS = -g -Wall

all: pt_walk

pt_walk: pt_walk.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f pt_walk