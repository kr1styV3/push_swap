/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:45:13 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/20 16:17:31 by chrlomba         ###   ########.fr       */
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
