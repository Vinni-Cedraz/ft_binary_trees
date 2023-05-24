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
