CFLAGS = -Wall -Wextra -Werror -g3

all: insert_data_test create_sorted_tree_test

insert_data_test:
	@$(CC) $(CFLAGS) btree_insert_data_test.c -o insert_data_test
	./insert_data_test

create_sorted_tree_test:
	@$(CC) $(CFLAGS) create_sorted_tree_test.c -o create_sorted_tree_test
	./create_sorted_tree_test

clean:
	rm -f insert_data_test
	rm -f create_sorted_tree_test
