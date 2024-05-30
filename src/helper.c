/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:45:13 by chrlomba          #+#    #+#             */
/*   Updated: 2024/05/29 11:46:54 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_print_stack(t_int_list *stack_a, t_int_list *stack_b)
{
	ft_printf("Stack A: ");
	while (stack_a != NULL)
	{
		ft_printf("%d ", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\nStack B: ");
	while (stack_b != NULL)
	{
		ft_printf("%d ", stack_b->content);
		stack_b = stack_b->next;
	}
	ft_printf("\n\n");
}

void	push_smallest_to_b(t_int_list **stack_a, t_int_list **stack_b)
{
	t_int_list	*current;
	int			smallest;
	int			position;
	int			index;

	current = *stack_a;
	smallest = current->content;
	position = 0;
	index = 0;
	while (current)
	{
		if (current->content < smallest)
		{
			smallest = current->content;
			position = index;
		}
		current = current->next;
		index++;
	}
	if (position <= 2)
		while (position-- > 0)
			ft_ra(stack_a);
	else
		while (position++ < 5)
			ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
}

void	ft_sort_five(t_int_list **stack_a, t_int_list **stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_four(t_int_list **stack_a, t_int_list **stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_three(t_int_list **stack_a)
{
	int		a;
	int		b;
	int		c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && b > c && a > c)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (a > b && a > c && b < c)
		ft_ra(stack_a);
	else if (a > b && a < c)
		ft_sa(stack_a);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack_a);
}

int	ft_small_check(t_int_list **stack_a, t_int_list **stack_b, int size)
{
	if (size <= 5)
	{
		if (size == 1)
			return (1);
		if (size == 2)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
				ft_sa(stack_a);
		}
		if (size == 3)
			ft_sort_three(stack_a);
		if (size == 4)
			ft_sort_four(stack_a, stack_b);
		if (size == 5)
		{
			ft_sort_five(stack_a, stack_b);
		}
		ft_print_stack(*stack_a, *stack_b);
		return (1);
	}
	return (0);
}
