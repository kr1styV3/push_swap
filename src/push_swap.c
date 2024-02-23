/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:59:38 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/23 13:48:07 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"


void	ft_push_swap(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_pivot_find(stack_a, stack_b, ft_int_lstsize(*stack_a));
	ft_bubble_sort(stack_a, stack_b);
	ft_print_stack(*stack_a, *stack_b);
	// ft_lis_find(stack_a);

}

void	ft_bubble_sort(t_int_list **stack_a, t_int_list **stack_b)
{
	int		i;
	int		size;

	size = ft_int_lstsize(*stack_a);
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_ra(stack_a);
		else if ((*stack_a)->content < (*stack_a)->next->content)
			ft_pb(stack_a, stack_b);
		if ((*stack_b)->content > (*stack_b)->next->content)
			ft_rb(stack_b);
		else if ((*stack_b)->content < (*stack_b)->next->content)
			ft_pa(stack_a, stack_b);
		ft_rr(stack_a, stack_b);
		ft_ss(stack_a, stack_b);
		i++;
	}
}

void	ft_pivot_find(t_int_list **stack_a, t_int_list **stack_b, int size)
{
	int		i;

	i = 0;
	while (i < size / 2)
	{
		ft_pb(stack_a, stack_b);
		i++;
	}
}

t_int_list	*ft_lis_find(t_int_list *stack_a)
{
	t_int_list	*stack_b;
	t_int_list	*tmp;

	stack_b = NULL;
	tmp = stack_a;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content > tmp->next->content)
		{
			ft_pb(&tmp, &stack_b);
			ft_print_stack(stack_a, stack_b);
		}
		tmp = tmp->next;
	}
	return (stack_b);
}
