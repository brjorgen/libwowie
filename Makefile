NAME=libwowie.a

all: data-structures utils mem buffers strings error bsvl search types link
	@echo "libwowie.a has been compiled for your system.\nIt can now be linked\
	 against your executable."

clean:
	@make clean -C mem
	@echo "Cleaned memory lib."
	@make clean -C error
	@echo "Cleaned error lib."
	@make clean -C BSVL
	@echo "Cleaned BSVL (linear algebra) lib."
	@make clean -C strings
	@echo "Cleaned string lib."
	@make clean -C data-structures
	@echo "Cleaned data structures."
	@make clean -C buffers
	@echo "Cleaned Buffer functions."
	@make clean -C search
	@echo "Cleaned search functions."
	@make clean -C utils
	@echo "Cleaned misc utility functions."
	@make clean -C types
	@echo "Cleaned type functions."

fclean:
	@make fclean -C mem
	@make fclean -C error
	@make fclean -C BSVL
	@make fclean -C strings
	@make fclean -C data-structures
	@make fclean -C buffers
	@make fclean -C search
	@make fclean -C utils
	@make clean -C types
	@rm $(NAME)
	@echo "Cleaned all object files and build executables."

data-structures:
	@make -C data-structures

mem:
	@make -C mem
	@echo "Compiled mem functions."

strings:
	@make -C strings
	@echo "Compiled string functions."

error:
	@make -C error
	@echo "Compiled error functions."

bsvl:
	@make -C BSVL
	@echo "Compiled BSVL (linear algebra lib)."

buffers:
	@make -C buffers
	@echo "Compiled buffer functions."

search:
	@make -C search
	@echo "Compiled search functions."

utils:
	@make -C utils
	@echo "Compiled misc util function."

types:
	@make -C types
	@echo "Compiled type conversion functions."

link:
	@echo "Linking all static libs into final lib..."
	@libtool -static -o $(NAME) ./mem/libwowie-mem.a	\
		./error/libwowie-error.a		\
		./BSVL/BSVL.a				\
		./strings/libwowie-strings.a		\
		./data-structures/libwowie-ds.a		\
		./buffers/libwowie-buffers.a		\
		./search/libwowie-search.a		\
		./types/libwowie-types.a		\
		./utils/libwowie-utils.a
	@echo "Done."

.PHONY: mem buffers data-structures strings error bsvl search types utils 
