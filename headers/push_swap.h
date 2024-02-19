/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:46:17 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/19 18:22:51 by chrlomba         ###   ########.fr       */
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
t_int_list		*arg_str_parsing(int argc, char **argv);
int			is_valid_number(char *str);

#endif
