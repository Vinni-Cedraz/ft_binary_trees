/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:46:35 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/24 18:06:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
#define FT_BTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum e_type { INT, CHAR, DOUBLE, FLOAT } t_var_types;

typedef void *x;

typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    void *item;
} t_btree;

void ft_print_node_int(void *item);
void ft_print_node_char(void *item);
void btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void btree_apply_infix(t_btree *root, void (*applyf)(void *));
void btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
t_btree *btree_create_node(void *item);
void safe_free(void *pointer);
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(x, x));

#endif
