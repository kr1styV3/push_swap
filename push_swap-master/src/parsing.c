/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:52 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/21 12:14:37 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_int_list	*arg_list_parsing(int argc, char **argv)
{
	t_int_list	*stack;
	t_int_list	*new_node;
	int			num;
	int			i;

	i = 2;
	if (ft_is_valid_input(argv[1]) == 0)
		return (NULL);
	stack = ft_int_lstnew(ft_atoi(argv[1]));
	if (!stack)
		return (NULL);
	while (i < argc)
	{
		if (ft_is_valid_input(argv[i]) == 0)
			ft_int_lstclear(stack);
		num = ft_atoi(argv[i]);
		new_node = ft_int_lstnew(num);
		if (!new_node)
			ft_int_lstclear(stack);
		ft_int_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}

t_int_list	*arg_str_parsing(char **argv)
{
	t_int_list	*stack;
	t_int_list	*new_node;
	char		**split;
	int			i;

	i = 1;
	split = ft_split(argv[1], ' ');
	if (!split)
		perror("Error\n");
	if (ft_is_valid_input(split[0]) == 0)
		return (NULL);
	stack = ft_int_lstnew(ft_atoi(split[0]));
	if (!stack)
		return (NULL);
	while (split[i])
	{
		if (ft_is_valid_input(split[i]) == 0)
			ft_int_lstclear(stack);
		new_node = ft_int_lstnew(ft_atoi(split[i]));
		if (!new_node)
			ft_int_lstclear(stack);
		ft_int_lstadd_back(&stack, new_node);
		i++;
	}
	ft_free_split(split);
	return (stack);
}
