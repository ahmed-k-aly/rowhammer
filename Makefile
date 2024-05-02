CC = gcc
CFLAGS = -g -Wall

all: pt_walk

pt_walk: pt_walk.c
	$(CC) $(CFLAGS) -o $@ $<

# make virt_to_phys_user.c file, which includes common.h header file
virt_to_phys_user.c: common.h
	$(CC) $(CFLAGS) -o $@ $<

# make virt_to_phys_user file
virt_to_phys_user: virt_to_phys_user.c
	$(CC) $(CFLAGS) -o $@ $< -lm


clean:
	rm -f pt_walk