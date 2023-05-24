/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:54:27 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/24 16:07:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// remember prefix traversal is a type of depth first search;
// apply applyf function on each node's item by using prefix traversal;

#include "../ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		applyf(root->item);
		btree_apply_prefix(root->left, applyf);
		btree_apply_prefix(root->right, applyf);
	}
}
