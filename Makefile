# Makefile for ncmct
ARCH := $(shell uname -m)
CC = gcc
CFLAGS = -Wall -ggdb
LDFLAGS = -lncursesw

ncmct : ncmct.o display.o
	$(CC) ncmct.o display.o -o ncmct.$(ARCH) $(LDFLAGS)

ncmct.o : ncmct.c
	$(CC) $(CFLAGS) -c ncmct.c $(LDFLAGS)

display.o : display.c display.h
	$(CC) $(CFLAGS) -c display.c $(LDFLAGS)

clean :
	$(RM) *.o
