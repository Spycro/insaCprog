CC=gcc
CFLAGS=-Wall -Werror

SRCS=test.c
OBJS=$(SRCS:.c=.o)
MAIN=$(OBJS:.o=)

$(MAIN): $(OBJS)
	$(CC) -o bin/$(MAIN) $(OBJS)

%.o: %.c$
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean

clean:
	rm *.o bin/$(MAIN)
