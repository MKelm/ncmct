# Makefile for ncmct
ARCH := $(shell uname -m)
CC = gcc
CFLAGS = -Wall -ggdb
LDFLAGS = -lncursesw -lpthread -lm

ncmct : ncmct.o helper.o display.o round.o companies.o
	$(CC) ncmct.o helper.o display.o round.o companies.o -o ncmct.$(ARCH) $(LDFLAGS)

ncmct.o : ncmct.c display.h round.h companies.h helper.h
	$(CC) $(CFLAGS) -c ncmct.c $(LDFLAGS)

helper.o : helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c $(LDFLAGS)

display.o : display.c display.h
	$(CC) $(CFLAGS) -c display.c $(LDFLAGS)

round.o : round.c round.h display.h
	$(CC) $(CFLAGS) -c round.c $(LDFLAGS)

companies.o : companies.c companies.h helper.h
	$(CC) $(CFLAGS) -c companies.c $(LDFLAGS)

clean :
	$(RM) *.o
