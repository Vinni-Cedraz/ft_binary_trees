/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:51:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/05/24 18:03:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_btree.h"

void	ft_print_node_int(void *item)
{
	if (item)
		printf("%d\n", *(int *)item);
	else if (NULL == item)
		printf("NULL\n");
}

void	ft_print_node_char(void *item)
{
	if (item)
		printf("%s\n", (char *)(item));
	else if (NULL == item)
		printf("NULL\n");
}
