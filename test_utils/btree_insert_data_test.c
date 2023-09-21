#include "../ex00/btree_create_node.c"
#include "../ex01/btree_apply_prefix.c"
#include "../ex02/btree_apply_infix.c"
#include "../ex03/btree_apply_suffix.c"
#include "../ex04/btree_insert_data.c"
#include "ft_create_sorted_tree.c"
#include "ft_delete_tree.c"
#include "ft_print_node.c"
#include "my_strcmp.c"
#include "safe_free.c"
#include "visualize_tree.c"
#include "visualize_tree_aux.c"

#define CYAN "\033[36m"
#define RESET "\033[0m"

typedef void	(*t_btree_apply_prefix)(t_btree *root, void (*applyf)(void *));
typedef enum e_index
{
	PREFIX,
	INFIX,
	SUFFIX
}				t_traversal_method_index;

// 	=====================      BTREE_INSERT_DATA TEST ====================  //
#include <string.h>

int	main(void)
{
	t_btree						*root = NULL;
	char						**str_arr;
	int							i;
	t_traversal_method_index	method_index;
    const char *words[26] = {
            "mango", "strawberry", "xylophone", "dog",   "violet", "fox",
            "grape", "jaguar",     "igloo",     "horse", "koala",  "lemon",
            "apple", "newt",       "banana",    "peach", "quail",  "rabbit",
            "tiger", "elephant",   "umbrella",  "zebra", "walrus", "cat",
            "yak",   "orange"
	};
	const t_btree_apply_prefix	traversal_method[] = {
		btree_apply_prefix, btree_apply_infix, btree_apply_suffix
	};
    const char *traversal_name[] = {
            CYAN"\nprefix traversal:\n"RESET, CYAN"\ninfix traversal:\n"RESET, CYAN"\nsuffix traversal:\n"RESET
	};

	str_arr = calloc(sizeof(char *), 29);
	for (i = 0; i < 26; i++)
		str_arr[i] = strdup(words[i]);
	// Three words starting with the same letter
	str_arr[26] = strdup("lion");
	str_arr[27] = strdup("lizard");
	str_arr[28] = strdup("leopard");
	for (int j = 0; j < 29; j++)
		btree_insert_data(&root, str_arr[j], my_strcmp);
	visualize_tree(root, CHAR);
	for (method_index = PREFIX; method_index <= SUFFIX; method_index++)
	{
		printf("%s", traversal_name[method_index]);
		traversal_method[method_index](root, ft_print_node_char);
	}
	btree_apply_suffix(root, safe_free);
	ft_delete_tree(root, safe_free);
	free(str_arr);
}
