/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:47:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/24 15:50:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_btree.h"

void	ft_delete_tree(t_btree *root, void(f_ptr)(void *))
{
	if (root)
	{
		ft_delete_tree(root->left, f_ptr);
		ft_delete_tree(root->right, f_ptr);
		f_ptr(root);
	}
}
