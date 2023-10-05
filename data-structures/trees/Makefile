NAME=libwowie-tree.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -g
INC=	./wowie_tree.h

SRC=	./tree_delete.c \
	./tree_insert.c \
	./tree_map.c \
	./tree_new.c

OBJ=	./tree_delete.o \
	./tree_insert.o \
	./tree_map.o \
	./tree_new.o

%.o : %.c $(INC)
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

test: all
	$(CC) $(CFLAGS) -g -o tree-test $(NAME) ./tree_test.c ./wowie_tree_error.c ../../error/error.c ../../mem/memdup.c
	codesign -s - -v -f --entitlements ./debug.plist tree-test

test-clean: fclean
	rm tree-test
