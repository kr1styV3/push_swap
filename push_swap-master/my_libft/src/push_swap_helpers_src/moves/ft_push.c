/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:21:59 by chrlomba          #+#    #+#             */
/*   Updated: 2024/06/11 18:24:47 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_helper.h"
#include "../headers/ft_printf.h"

void	ft_push(t_int_list **from, t_int_list **to)
{
	t_int_list	*tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	if (*to != NULL)
		(*to)->prev = tmp;
	tmp->prev = NULL;
	*to = tmp;
}

void	ft_pa(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_pb(t_int_list **stack_a, t_int_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
