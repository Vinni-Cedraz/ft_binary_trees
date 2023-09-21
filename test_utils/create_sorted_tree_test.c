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

typedef void	(*t_btree_apply_prefix)(t_btree *root, void (*applyf)(void *));
typedef enum e_index
{
	PREFIX,
	INFIX,
	SUFFIX
}				t_traversal_method_index;

int	main(void)
{
	t_btree							*root;
	int								start;
	int								*arr;
	const t_traversal_method_index	method_index = PREFIX;
	const t_btree_apply_prefix		traversal_method[] = {
		btree_apply_prefix, btree_apply_infix, btree_apply_suffix
	};
	const char						*traversal_name[] = {
		"prefix traversal:\n", "infix traversal:\n", "suffix traversal:\n"
	};

	root = NULL;
	start = 50;
	ft_create_sorted_tree(&root, &start);
	arr = malloc(sizeof(int) * 150);
	srand(time(NULL) ^ (getpid() << 16));
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 100;
		if (i > 0)
			while (arr[i] == arr[i - 1])
				arr[i] = rand() % 100;
		ft_create_sorted_tree(&root, &arr[i]);
	}
	visualize_tree(root, INT);
	printf("%s", traversal_name[method_index]);
	traversal_method[method_index](root, ft_print_node_int);
	ft_delete_tree(root, safe_free);
	free(arr);
}
