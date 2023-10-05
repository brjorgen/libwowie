NAME=libwowie-search.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -g3
INC= ./search.h
SRC= ./search.c
OBJ= ./search.o

%.o : %.c $(INC)
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

test-clean: fclean
	rm test.bin
