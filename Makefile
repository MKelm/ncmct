# Makefile for ncmct
ARCH := $(shell uname -m)
CC = gcc
CFLAGS = -Wall -ggdb
LDFLAGS = -lncursesw -lpthread

ncmct : ncmct.o display.o round.o
	$(CC) ncmct.o display.o round.o -o ncmct.$(ARCH) $(LDFLAGS)

ncmct.o : ncmct.c display.h round.h
	$(CC) $(CFLAGS) -c ncmct.c $(LDFLAGS)

display.o : display.c display.h
	$(CC) $(CFLAGS) -c display.c $(LDFLAGS)

round.o : round.c round.h display.h
	$(CC) $(CFLAGS) -c round.c $(LDFLAGS)

clean :
	$(RM) *.o
