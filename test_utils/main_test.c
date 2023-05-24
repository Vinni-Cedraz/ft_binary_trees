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

// 	===================      FT_CREATE_SORTED_TREE TEST ====================  //
// int	main(void)
// {
// 	t_btree	*root;
// 	int		start;
// 	int		*arr;
//
// 	root = NULL;
// 	start = 50;
// 	ft_create_sorted_tree(&root, &start);
//
// 	// allocation
// 	arr = malloc(sizeof(int) * 150);
//
// 	srand(time(NULL) ^ (getpid() << 16));
// 	for (int i = 0; i < 10; i++)
// 	{
// 		arr[i] = rand() % 100;
// 		ft_create_sorted_tree(&root, &arr[i]);
// 	}
// 	visualize_tree(root);
// 	printf("\n");
// 	printf("\n");
// 	printf("suffix traversal:\n");
// 	btree_apply_suffix(root, ft_print_node_int);
// 	ft_delete_tree(root, safe_free);
// 	free(arr);
// }

// 	=====================      BTREE_INSERT_DATA TEST ====================  //
#include <string.h>
int main(void) {
    t_btree *root;
    char **str_arr;
    int i;

    root = NULL;
    str_arr = calloc(sizeof(char *), 29);

	    const char *words[26] = {
        "mango",      "strawberry", "xylophone",      "dog",    "violet", "fox",
        "grape",      "jaguar",     "igloo",    "horse",  "koala",    "lemon",
        "apple",      "newt",       "banana",   "peach",  "quail",    "rabbit",
        "tiger",      "elephant",     "umbrella", "zebra",  "walrus",   "cat",
        "yak",        "orange"
    };
    for (i = 0; i < 26; i++) {
        str_arr[i] = strdup(words[i]);
    }

    // Three words starting with the same letter
    str_arr[26] = strdup("lion");
    str_arr[27] = strdup("lizard");
    str_arr[28] = strdup("leopard");

    // INSERT DATA
    for (int a = 0; a < 29; a++)
        btree_insert_data(&root, str_arr[a], my_strcmp);
    visualize_tree(root, CHAR);
    btree_apply_infix(root, ft_print_node_char);
    btree_apply_suffix(root, safe_free);
    ft_delete_tree(root, safe_free);
    free(str_arr);
}
