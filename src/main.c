/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:45:13 by chrlomba          #+#    #+#             */
/*   Updated: 2024/05/30 18:29:34 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// void	ft_sort_insertion(t_int_list **stack_a)
// {
// 	int				size;
// 	int				i;
// 	int				j;
// 	int				k;

// 	size = ft_int_lstsize(*stack_a);
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size - i - 1)
// 		{
// 			if ((*stack_a)->content > (*stack_a)->next->content)
// 			{
// 				ft_sa(stack_a);
// 			}
// 			ft_ra(stack_a);
// 			j++;
// 		}
// 		k = 0;
// 		while (k < size - i - 1)
// 		{
// 			ft_rra(stack_a);
// 			k++;
// 		}
// 		i++;
// 	}
// }

void	ft_lis(t_int_list **stack_a, t_int_list **stack_b)
{
	int			size;
	int			i;
	int			*tmp;
	t_int_list	*current;

	size = ft_int_lstsize(*stack_a);
	current = *stack_a;
	i = 0;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		perror("Error\n");
	tmp[i] = current->content;
	current = current->next;
	while (i < size - 1)
	{
		if (tmp[i] < current->content)
		{
			ft_ra(stack_a);
			tmp[i + 1] = current->content;
		}
		else
			break ;
		current = current->next;
		i++;
	}
	ft_ra(stack_a);
	while (tmp[0] != (*stack_a)->content)
		ft_pb(stack_a, stack_b);
	free(tmp);
}

int	main(int argc, char **argv)
{
	t_int_list		*stack_a;
	t_int_list		*stack_b;

	if (ft_check_input(argc, argv) == 0)
		stack_a = arg_str_parsing(argv);
	else
		stack_a = arg_list_parsing(argc, argv);
	stack_b = NULL;
	if (ft_small_check(&stack_a, &stack_b, ft_int_lstsize(stack_a)) == 1)
		return (0);
	ft_lis(&stack_a, &stack_b);
	ft_print_stack(stack_a, stack_b);
	return (0);
}
