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

static void	print_tree(t_btree *root, int distance, t_var_types type);

void		visualize_tree(t_btree *root, t_var_types type)
{
	printf(CYAN "Tree visualization:\n\n\n" RESET);
	print_tree(root, 0, type);
	printf("\n\n");
}

static void	print_tree(t_btree *root, int distance, t_var_types type)
{
	if (root == NULL)
		return ;
	distance += SPACES;
	print_tree(root->right, distance, type);
	print_right_branch(distance + 2, root->right);
	print_item(root, type, distance);
	print_left_branch(distance + 2, root->left);
	print_tree(root->left, distance, type);
}
