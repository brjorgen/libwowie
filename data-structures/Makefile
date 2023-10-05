NAME=libwowie-ds.a
CC=clang
CFLAGS= -Wall -Werror -Wextra

all: 	ds
	@echo "linking structures static libs..."
	@libtool -static -o libwowie-ds.a \
	linked-lists/libwowie-lists.a \
	stacks/libwowie-stacks.a \
	trees/libwowie-tree.a \
	hashmaps/libwowie-hashmaps.a \
	heaps/libwowie-heaps.a
	@echo "Compiled data structures."

re:	fclean
	all

ds:
	@make -C hashmaps
	@echo "compiled hashmasps"
	@make -C heaps
	@echo "compiled heaps"
	@make -C linked-lists
	@echo "compiled linked lists"
	@make -C stacks
	@echo "compiled stacks"
	@make -C trees
	@echo "compiled trees"

clean:
	make -C hashmaps clean
	make -C heaps clean
	make -C linked-lists clean
	make -C stacks clean
	make -C trees clean

fclean:
	make -C hashmaps fclean
	make -C heaps fclean
	make -C linked-lists fclean
	make -C stacks fclean
	make -C trees fclean
	rm ./$(NAME)

test:
	make -C linked-lists test
	make -C stacks test
	make -C stacks ltest
	make -C trees test
	make -C hashmaps test
	make -C heaps test

	@echo "============================================[TESTS: Linked list]="
	./linked-lists/list-test a b c
	@echo "=================================================[TESTS: Stacks]="
	./stacks/stack-test
	@echo "=========================================[TESTS: Dynamic Stacks]="
	./stacks/lstack-test
	@echo "===============================================[TESTS: Hashmaps]="
	./hashmaps/hashmap-test
	@echo "==================================================[TESTS: Heaps]="
	./heaps/heap-test
	@echo "==================================================[TESTS: Trees]="
	./trees/tree-test "Hello my dear friend"

	@# @echo "==============================================[TESTS: Dynarrays]="
	@# ./dynarray/dynarray-test
