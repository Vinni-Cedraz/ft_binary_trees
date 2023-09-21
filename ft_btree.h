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
# define FT_BTREE_H

# define SPACES 4
# define CYAN "\033[36m"
# define RESET "\033[0m"

# include <stdio.h>
# include <stdlib.h>

typedef enum e_type
{
	INT,
	CHAR,
	DOUBLE,
	FLOAT
}					t_var_types;

typedef void		*x;

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

void	ft_print_node_int(void *item);
void	ft_print_node_char(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(t_btree **r, void *i, int (*cmp)(void *, void *));
t_btree	*btree_create_node(void *item);
void	safe_free(void *pointer);
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(x, x));
void	print_item(t_btree *this_node, t_var_types type, int distance);
void	print_left_branch(int distance, t_btree *left);
void	print_right_branch(int distance, t_btree *right);
void	print_distance(int distance);

#endif
