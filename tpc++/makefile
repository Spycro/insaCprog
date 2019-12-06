CC=g++
CFLAGS= -ansi -pedantic –Wall –std=c++11 -D MAP -g

SRCS=TrajetSimple.cpp main.cpp TrajetCompose.cpp Catalogue.cpp
OBJS=$(SRCS:.cpp=.o)
MAIN=main

$(MAIN): $(OBJS)
	$(CC) -o bin/$(MAIN) $(OBJS) -DMAP

%.o: %.c$
	$(CC) $(CFLAGS) -c $< -o $@ -DMAP


.PHONY: clean

clean:
	rm *.o bin/$(MAIN)
