CFLAGS = -Wall -Wextra -Werror -O3 -lcriterion

all:
	@$(CC) $(CFLAGS) create_sorted_tree_test.c -o create_sorted_tree_test
	./create_sorted_tree_test --verbose

clean:
	rm -f create_sorted_tree_test
