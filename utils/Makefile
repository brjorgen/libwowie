NAME=libwowie-utils.a
CC=clang
CFLAGS=-Wall -Werror -Wextra
INC=	./utils.h ./bprint.h
SRC=	parse_flags.c \
	usage.c	      \
	bprint/bprint.c

OBJ=	parse_flags.o \
	usage.o \
	bprint.o

%.o : %.c $(INC)
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

# test: all
# 	$(CC) $(CFLAGS) -o uti-test.bin mem_test.o libwowie-mem.a

test-clean: fclean
	rm mem-test.bin
