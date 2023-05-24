/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:50:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/24 17:13:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_btree.h"

typedef void	*x;

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(x, x))
{
	if (!*root)
		*root = btree_create_node(item);
	else if (0 < cmpf(item, (*root)->item))
		btree_insert_data(&(*root)->right, item, cmpf);
	else
		btree_insert_data(&(*root)->left, item, cmpf);
}
