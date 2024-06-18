/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:29:10 by chrlomba          #+#    #+#             */
/*   Updated: 2024/05/10 18:54:08 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_helper.h"

t_int_list	*ft_int_lstnew(int content)
{
	t_int_list	*tmp;

	tmp = (t_int_list *)malloc(sizeof(t_int_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}
