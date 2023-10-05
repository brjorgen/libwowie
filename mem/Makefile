NAME=libwowie-mem.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -g
INC=	./mem.h
SRC=	bzero.c \
	memccpy.c \
	memchr.c \
	memcmp.c \
	memcpy.c \
	memdup.c \
	memmove.c \
	memalloc.c \
	memset.c \
	free2darray.c

OBJ=	bzero.o \
	memccpy.o \
	memchr.o \
	memcmp.o \
	memcpy.o \
	memdup.o \
	memmove.o \
	memalloc.o \
	memset.o \
	free2darray.o

%.o : %.c $(INC)
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

test: all
	$(CC) $(CFLAGS) -o mem-test.bin mem-test.c libwowie-mem.a

test-clean:
	rm mem-test.bin
