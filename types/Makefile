NAME=libwowie-types.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -g3
INC= ./types.h
SRC= ./u16tou8s.c  \
     ./u16stou32.c \
     ./u8stou32.c  \
     ./u8stou16.c  \
     ./u32tou16s.c

OBJ= ./u16tou8s.o  \
     ./u16stou32.o \
     ./u8stou32.o  \
     ./u8stou16.o  \
     ./u32tou16s.o

%.o : %.c $(INC)
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

test: 	all
	$(CC) $(CFLAGS) test.c $(NAME) -o types-test

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

test-clean: fclean
	rm types-test
