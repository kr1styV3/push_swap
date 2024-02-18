/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:52 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/18 23:58:13 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*parse(int argc, char **argv)
{
	t_list	*stack;
	t_list	*new_node;
	int		num;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		new_node = ft_lstnew(num);
		if (!new_node)
			clear(&stack);
		if (number_exists(stack, num))
			exit(1);
		if (!is_valid_number(argv[i]))
			return (NULL);
		ft_lstadd_front(&stack, new_node);
	}
	return (stack);
}

void	clear(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
