NAME=libwowie-hashmaps.a
CC=clang
CFLAGS= -Wall -Werror -Wextra
SRCDIR=src
OBJDIR=tmp
BUILDDIR=.
SRC=	$(wildcard $(SRCDIR)/*.c)
OBJ =   $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
INC= -I./inc -I../../mem/ -I../../strings/

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(INC) $(CFLAGS) -c -o $@ $< 

all : setup $(OBJ)
	@ar rc $(BUILDDIR)/$(NAME) $(OBJ)
	@ranlib $(BUILDDIR)/$(NAME)

setup:
	@mkdir -p $(BUILDDIR) $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm $(NAME)

test:
	$(CC) $(CFLAGS) $(BUILDDIR)/$(NAME) src/hashmap-test.c ../../mem/memalloc.c ../../mem/bzero.c ../../mem/memset.c  -o hashmap-test
