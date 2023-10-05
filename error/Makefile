NAME=libwowie-error.a
CC=clang
CFLAGS=-Wall -Werror -Wextra
OBJ=error.o
INC=error.h
SRC=error.c

%.o : %.c $(INC)
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

test-clean: fclean
	rm test.bin
