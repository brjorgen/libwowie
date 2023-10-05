NAME=libwowie-stacks.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -g
INC=	./wowie_stacks.h \
	./wowie_lstacks.h

SRC=	./wowie_stacks.c  \
	./stack_error.c \
	./wowie_lstacks.c

ERR_SRC = ../../error/error.c

OBJ=	./wowie_stacks.o  \
	./stack_error.o \
	./wowie_lstacks.o

TESTSRC=./stack_test.c \
	./lstack_test.c

%.o : %.c $(INC)
	@ $(CC) -c -o $@ $< $(CFLAGS)

all : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

test: all
	$(CC) $(CFLAGS) $(NAME) -DDEBUG ./stack_test.c $(ERR_SRC) -o stack-test

ltest: all
	gcc -g -DDEBUG lstack_test.c ../linked-lists/libwowie-lists.a wowie_lstacks.o ../../error/libwowie-error.a ../../mem/libwowie-mem.a  -o lstack-test
