# This makefile compiles the BSVL, a simple linear algebra library.
# Makefile was auto-generated.
# Sour cream and onions!

CC	=	gcc
INFILE  =	math_utils.c	\
		vec2.c		\
		vec3.c		\
		vec4.c

OUTFILE = 	BSVL.a
FLAGS   = 	-Wall -Werror -Wextra
OBJ     = 	$(INFILE:%.c=%.o)
HEADER  = 	BSVL.h

%.o: %.c	 $(HEADER)
	 	 @$(CC) -o $@ -c $< $(CFLAGS)

all :    	 $(OBJ)
	 	 @ar rc $(OUTFILE) $(OBJ)
	 	 @ranlib $(OUTFILE)
	 	 @echo "BSVL: compiled static library."

clean:
		@rm -f $(OBJ)
		@echo "BSVL: Removed object files."

fclean: 	clean
		@rm -f $(OUTFILE)
		@echo "BSVL: Removed static library."

re:		fclean all
