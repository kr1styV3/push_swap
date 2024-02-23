/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:46:17 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/23 13:45:14 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../my_libft/headers/libft.h"
# include "../my_libft/headers/ft_printf.h"
# include "../my_libft/headers/push_swap_helper.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_int_list		*arg_list_parsing(int argc, char **argv);
t_int_list		*arg_str_parsing(char **argv);
void			ft_push_swap(t_int_list **stack_a, t_int_list **stack_b);

// helper
void			ft_print_stack(t_int_list *stack_a, t_int_list *stack_b);
t_int_list		*ft_lis_find(t_int_list *stack_a);
void			ft_pivot_find(t_int_list **stack_a,
					t_int_list **stack_b, int size);
void			ft_bubble_sort(t_int_list **stack_a, t_int_list **stack_b);

#endif
