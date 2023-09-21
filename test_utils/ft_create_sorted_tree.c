/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sorted_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:53:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/24 16:54:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_btree.h"
#include "../ex00/btree_create_node.c"
#include "../ex01/btree_apply_prefix.c"
#include "../ex02/btree_apply_infix.c"
#include "../ex03/btree_apply_suffix.c"
#include "../ex04/btree_insert_data.c"
#include "ft_delete_tree.c"
#include "ft_print_node.c"
#include "my_strcmp.c"
#include "safe_free.c"
#include "visualize_tree.c"
#include "visualize_tree_aux.c"
#include <string.h>

#define TEST_SUITE_NAME ft_binary_trees
typedef void	(*t_btree_apply_prefix)(t_btree *root, void (*applyf)(void *));
typedef enum e_index
{
	PREFIX,
	INFIX,
	SUFFIX
}				t_traversal_method_index;

t_btree	*ft_create_sorted_tree(t_btree **root, int *value)
{
	if (!*root)
		*root = btree_create_node(value);
	else if (*value >= *(int *)(*root)->item)
		ft_create_sorted_tree(&(*root)->right, value);
	else
		ft_create_sorted_tree(&(*root)->left, value);
	return (*root);
}

void *create_sorted_tree_with_100_ints(void *root_void)
{
	int								start;
	int								*arr;

	t_btree *root = (t_btree *)root_void;
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
	return (root);
}

void *create_sorted_tree_of_words(void *root_void)
{
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

	t_btree *root = (t_btree*)root_void;
	str_arr = calloc(sizeof(char *), 29);
	for (i = 0; i < 26; i++)
		str_arr[i] = strdup(words[i]);
	str_arr[26] = strdup("lion"), str_arr[27] = strdup("lizard"), str_arr[28] = strdup("leopard"); // Three words starting with the same letter
	for (int j = 0; j < 29; j++)
		btree_insert_data(&root, str_arr[j], my_strcmp);
	visualize_tree(root, CHAR);
	for (method_index = PREFIX; method_index <= SUFFIX; method_index++)
	{
		printf("%s", traversal_name[method_index]);
		traversal_method[method_index](root, ft_print_node_char);
	}
	free(str_arr);
	return (root);
}
