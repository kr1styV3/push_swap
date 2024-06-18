/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:46:17 by chrlomba          #+#    #+#             */
/*   Updated: 2024/06/13 19:11:39 by chrlomba         ###   ########.fr       */
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
int				ft_small_check(t_int_list **stack_a, t_int_list **stack_b, int size);
void			ft_print_stack(t_int_list *stack_a, t_int_list *stack_b);
void			ft_sort_three(t_int_list **stack_a);
void			ft_sort_four(t_int_list **stack_a, t_int_list **stack_b);
void			ft_sort_five(t_int_list **stack_a, t_int_list **stack_b);
void			push_smallest_to_b(t_int_list **stack_a, t_int_list **stack_b);
void			ft_sort_insertion(t_int_list **stack_a);
int				ft_int_lstsize(t_int_list *lst);
void			ft_int_lstadd_back(t_int_list **lst, t_int_list *new);
void			ft_int_lstclear(t_int_list *ptr);
t_int_list		*ft_int_lstnew(int content);

void apply_final_rotations(t_int_list **stack, int rotations);
int calculate_final_rotations(t_int_list *stack);
void apply_rotations(t_int_list **stack_a, t_int_list **stack_b, int target_pos);
int calculate_best_rotations(t_int_list **stack_a, t_int_list **stack_b, int target_pos);
int find_best_position(t_int_list *stack, int value);
#endif
