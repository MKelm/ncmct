# Makefile for ncmct
ARCH := $(shell uname -m)
CC = gcc
CFLAGS = -Wall -ggdb
LDFLAGS = -lncursesw

ncmct : ncmct.o
	$(CC) ncmct.o -o ncmct.$(ARCH) $(LDFLAGS)

ncmct.o : ncmct.c
	$(CC) $(CFLAGS) -c ncmct.c $(LDFLAGS)

clean :
	$(RM) *.o
