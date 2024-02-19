/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:48:52 by chrlomba          #+#    #+#             */
/*   Updated: 2024/02/19 18:30:52 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_int_list	*arg_list_parsing(int argc, char **argv)
{
	t_int_list	*stack;
	t_int_list	*new_node;
	int		num;
	int		i;

	i = 1;
	stack = malloc(sizeof(t_int_list *));
	if (!stack)
		return (NULL);
	while (i < argc)
	{
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

	i = 0;
	stack = malloc(sizeof(t_int_list *));
	if (!stack)
		return (NULL);
	split = ft_split(argv[1], ' ');
	if (!split)
		ft_int_lstclear(stack);
	while (split[i])
	{
		new_node = ft_int_lstnew(ft_atoi(split[i]));
		if (!new_node)
			ft_int_lstclear(stack);
		ft_int_lstadd_back(&stack, new_node);
		i++;
	}
	ft_free_split(split);
	return (stack);
}
