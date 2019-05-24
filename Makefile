CC=gcc
CFLAGS=-O3 -Wall -Werror -Wextra

clean:
	rm -f *.o *.out

nn.o: nn.c nn.h
	$(CC) $(CFLAGS) -c $< -o $@

main.out: main.c nn.o
	$(CC) $(CFLAGS) $^ -o $@

run: main.out
	./$<