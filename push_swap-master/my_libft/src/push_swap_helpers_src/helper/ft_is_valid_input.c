/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:12:51 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/21 12:35:41 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_helper.h"
#include "../headers/libft.h"
#include "../headers/ft_printf.h"

int	ft_is_valid_input(char *str)
{
	if (*str == '-')
		++str;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_printf("invalid input\n");
			return (0);
		}
		++str;
	}
	return (1);
}
