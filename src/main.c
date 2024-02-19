/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:45:13 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/19 18:22:53 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_int_list		*head;
	t_int_list		*stack_a;

	if (check_input(argc, argv) == 0)
		head = arg_str_parsing(argc, argv);
	else
		head = arg_list_parsing(argc, argv);
	stack_a = head;
	while (stack_a)
	{
		ft_printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return (0);
}
