CC=g++
CFLAGS=-ansi -pedantic –Wall –std=c++11 -g -DMAP

SRCS=TrajetSimple.cpp main.cpp TrajetCompose.cpp Catalogue.cpp
OBJS=$(SRCS:.cpp=.o)
MAIN=main

$(MAIN): $(OBJS)
	$(CC) -o bin/$(MAIN) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -DMAP -c $< -o $@


.PHONY: clean

clean:
	rm *.o bin/$(MAIN)
