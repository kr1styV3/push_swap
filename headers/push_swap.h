/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:46:17 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/19 00:18:46 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../my_libft/headers/libft.h"
# include "../my_libft/headers/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_list		*parse(int argc, char **argv);
int			number_exists(t_list *stack, int num);
int			is_valid_number(char *str);
void		clear(t_list **stack);
void		ft_start(t_list *stack_a, t_list *stack_b);
void		ft_sort(t_list *stack_a, t_list *stack_b);
char		*ft_putnbr(int n);


#endif
