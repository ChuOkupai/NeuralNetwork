LIB = libperceptron.a
CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror
LDFLAGS = -I./include -L. -lperceptron

all: $(test)

%.o: %.c include/*.h
	$(CC) $(CFLAGS) -c $< -o $@ -I./include

$(LIB): src/perceptron.o
	ar rcs $@ $<

%.out: %.c include/*.h $(LIB)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# call this with test-boolean or test-pix
test-%: test/%.out
	./$<

clean:
	rm -f src/*.o

fclean: clean
	rm -f $(LIB) test/*.out

re: fclean all

.PHONY: clean fclean re