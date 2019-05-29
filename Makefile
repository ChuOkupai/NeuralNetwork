CC=gcc
CFLAGS=-O3 -Wall -Werror -Wextra

clean:
	rm -f *.o *.out

nn.o: nn.c nn.h
	$(CC) $(CFLAGS) -c $< -o $@

%.out: %.c nn.o
	$(CC) $(CFLAGS) $^ -o $@

run: boolean.out
	./$<