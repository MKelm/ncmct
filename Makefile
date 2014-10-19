# Makefile for ncmct
ARCH := $(shell uname -m)
CC = gcc
CFLAGS = -Wall -ggdb
LDFLAGS = -lncursesw -lpthread -lm

ncmct : ncmct.o helper.o display.o round.o companies.o technology.o player.o
	$(CC) ncmct.o helper.o display.o round.o companies.o technology.o player.o -o ncmct.$(ARCH) $(LDFLAGS)

ncmct.o : ncmct.c display.h round.h companies.h helper.h technology.h player.h
	$(CC) $(CFLAGS) -c ncmct.c $(LDFLAGS)

helper.o : helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c $(LDFLAGS)

display.o : display.c display.h
	$(CC) $(CFLAGS) -c display.c $(LDFLAGS)

round.o : round.c round.h display.h
	$(CC) $(CFLAGS) -c round.c $(LDFLAGS)

technology.o : technology.c technology.h
	$(CC) $(CFLAGS) -c technology.c $(LDFLAGS)

companies.o : companies.c companies.h helper.h technology.h
	$(CC) $(CFLAGS) -c companies.c $(LDFLAGS)

player.o : player.c player.h companies.h technology.h
	$(CC) $(CFLAGS) -c player.c $(LDFLAGS)

clean :
	$(RM) *.o
