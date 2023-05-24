/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:56:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/24 18:09:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_btree.h"

#define COUNT 4

static void	print2DUtil(t_btree *root, int space, t_var_types type);

void	visualize_tree(t_btree *root, t_var_types type)
{
	print2DUtil(root, 0, type);
}

static void	print2DUtil(t_btree *root, int space, t_var_types type)
{
	if (root == NULL)
		return ;
	space += COUNT;
	print2DUtil(root->right, space, type);
	for (int i = COUNT; i < space; i++)
		printf(" ");
	if (INT == type)
		printf("%d\n", *(int *)root->item);
	else if (CHAR == type)
		printf("%s\n", (char *)root->item);
	print2DUtil(root->left, space, type);
}
