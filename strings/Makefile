NAME=libwowie-strings.a
CC=clang
CFLAGS=-Wall -Werror -Wextra
SRC=	./atoi.c \
	./intlen.c \
	./itoa.c \
	./putchar.c \
	./putnbr.c \
	./putstr.c \
	./str_bin_search.c \
	./strchr.c \
	./strclean.c \
	./strcmp.c \
	./strcspn.c \
	./strdup.c \
	./strlen.c \
	./strncpy.c \
	./strnext.c \
	./strstr.c
INC=	./strings.h
OBJ=	./atoi.o \
	./intlen.o \
	./itoa.o \
	./putchar.o \
	./putnbr.o \
	./putstr.o \
	./str_bin_search.o \
	./strchr.o \
	./strclean.o \
	./strcmp.o \
	./strcspn.o \
	./strdup.o \
	./strlen.o \
	./strncpy.o \
	./strnext.o \
	./strstr.o

%.o : %.c $(INC)
	 @$(CC) -c $< $(CFLAGS) -o $@

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)
