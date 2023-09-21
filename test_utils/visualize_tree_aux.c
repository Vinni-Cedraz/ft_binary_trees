# include "../ft_btree.h"

void	print_distance(int distance)
{
	for (int i = SPACES; i < distance; i++)
		printf(" ");
}

void print_right_branch(int distance, t_btree *right)
{
	if (!right)
		return ;
	print_distance(distance);
    printf("/\n");
}

void print_left_branch(int distance, t_btree *left)
{
	if (!left)
		return ;
	print_distance(distance);
    printf("\\\n");
}

void	print_item(t_btree *this_node, t_var_types type, int distance)
{
	print_distance(distance);
	if (INT == type)
		printf("%d\n", *(int *)this_node->item);
	else if (CHAR == type)
		printf("%s\n", (char *)this_node->item);
}
