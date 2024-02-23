/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:45:13 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/23 13:31:05 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*TODO parsing:
	*
	* - controllare i doppioni (sortare e poi controllare se i due vicini sono uguali) / (+0 -0)
	* -controllare "2 + 2" deve essere errore
	* controllare "2 a 3" deve essere errore
	* gestiti MAX_INT E MIN_INT
	* prima di fare qualsiasi altra cosa controlla se l input e' gia in ordine
	*/

int	main(int argc, char **argv)
{
	t_int_list		*stack_a;
	t_int_list		*stack_b;

	if (ft_check_input(argc, argv) == 0)
		stack_a = arg_str_parsing(argv);
	else
		stack_a = arg_list_parsing(argc, argv);
	stack_b = NULL;
	ft_push_swap(&stack_a, &stack_b);
	return (0);
}
