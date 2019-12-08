CC=g++
CFLAGS=-ansi -std=c++11 -pedantic -Wall
DEBUGFLAGS=-g -DMAP


SRCS=TrajetSimple.cpp main.cpp TrajetCompose.cpp Catalogue.cpp
OBJS=$(SRCS:.cpp=.o)
MAIN=main

debug: CFLAGS += DEBUGFLAGS 



$(MAIN): $(OBJS)
	$(CC) -o bin/$(MAIN) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@



.PHONY: clean

clean:
	rm *.o bin/$(MAIN)
