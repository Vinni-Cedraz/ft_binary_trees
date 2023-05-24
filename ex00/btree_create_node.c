/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:47:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/24 16:54:28 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>

#include "../ft_btree.h"

// creates a node with *item as its item and two leafs (NULLs) to left and right
t_btree *btree_create_node(void *item) {
    t_btree *new_node;

    new_node = malloc(sizeof(t_btree));
    new_node->item = item;
    new_node->right = NULL;
    new_node->left = NULL;
    return (new_node);
}
