NAME=libwowie-heaps.a
INC= heaps.h
SRC= wowie-heaps.c
CFLAGS= -Wall -Werror -Wextra

all:
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) wowie-heaps.o
	@ranlib $(NAME)

clean:
	rm wowie-heaps.o

fclean: clean
	rm $(NAME)

test: all
	@$(CC) $(NAME) heap_test.c ../../mem/memset.c -o heap-test
	@echo "Compiled heap test executable."
