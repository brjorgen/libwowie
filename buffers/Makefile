NAME=libwowie-buffers.a
CC=clang
CFLAGS=-Wall -Werror -Wextra
SRC=		./buff_flush.c        \
	        ./buff_get_input.c    \
	  	./buff_get_remainder.c\
	  	./buff_init.c         \
		./buff_write.c        \
		./buff_clear.c

INC =   ./buffers.h ../mem/mem.h ../strings/strings.h

OBJ=		./buff_flush.o        \
	        ./buff_get_input.o    \
	  	./buff_get_remainder.o\
	  	./buff_init.o         \
		./buff_write.o        \
		./buff_clear.o

%.o : %.c $(INC)
	@$(CC) -c -o $@ $< $(CFLAGS)

all : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)
