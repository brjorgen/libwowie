NAME=libwowie-lists.a
CC=clang
CFLAGS=-Wall -Werror -Wextra -g
INC=./wowie_lists.h

SRC=	lst_attach_end.c \
	lst_attach_start.c \
	lst_clear.c \
	lst_cpy_link.c \
	lst_cpy_lst.c \
	lst_delete_link.c \
	lst_find_end.c \
	lst_find_prev.c \
	lst_fold.c \
	lst_insert_link_next.c \
	lst_insert_link_prev.c \
	lst_len.c \
	lst_map.c \
	lst_new_link.c \
	lst_search_brute_no_ref.c \
	lst_search_brute_with_ref.c \
	lst_delete_lst.c \
	wowie_lst_error.c

OBJ=	lst_attach_end.o \
	lst_attach_start.o \
	lst_clear.o \
	lst_cpy_link.o \
	lst_cpy_lst.o \
	lst_delete_link.o \
	lst_find_end.o \
	lst_find_prev.o \
	lst_fold.o \
	lst_insert_link_next.o \
	lst_insert_link_prev.o \
	lst_len.o \
	lst_map.o \
	lst_new_link.o \
	lst_search_brute_no_ref.o \
	lst_search_brute_with_ref.o \
	lst_delete_lst.o \
	wowie_lst_error.o

TESTDEP= ../../mem/libwowie-mem.a\
	./wowie_lst_error.c \
	../../error/error.c \
	../../mem/libwowie-mem.a

%.o : %.c $(INC)
	@$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

test: all
	$(CC) $(CFLAGS) -o list-test $(NAME) ./list_test.c $(TESTDEP)

test-clean: fclean
	rm ./list_test.c
