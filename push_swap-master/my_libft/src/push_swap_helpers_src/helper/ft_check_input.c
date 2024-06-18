/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:11:49 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/19 18:20:37 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_helper.h"

int	ft_check_input(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_is_valid_input(argv[1]) == 0)
			return (0);
	}
	return (1);
}
