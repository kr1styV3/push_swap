/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrlomba <chrlomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:45:13 by chrlomba          #+#    #+#             */
/*   Updated: 2024/06/13 19:42:00 by chrlomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <limits.h>

// void	ft_sort_insertion(t_int_list **stack_a)
// {
// 	int				size;
// 	int				i;
// 	int				j;
// 	int				k;

// 	size = ft_int_lstsize(*stack_a);
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size - i - 1)
// 		{
// 			if ((*stack_a)->content > (*stack_a)->next->content)
// 			{
// 				ft_sa(stack_a);
// 			}
// 			ft_ra(stack_a);
// 			j++;
// 		}
// 		k = 0;
// 		while (k < size - i - 1)
// 		{
// 			ft_rra(stack_a);
// 			k++;
// 		}
// 		i++;
// 	}
// }


void	ft_lis(t_int_list **stack_a, t_int_list **stack_b)
{
	int			size;
	int			i;
	int			*tmp;
	t_int_list	*current;

	size = ft_int_lstsize(*stack_a);
	current = *stack_a;
	i = 0;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		perror("Error\n");
	tmp[i] = current->content;
	current = current->next;
	while (i < size - 1)
	{
		if (tmp[i] < current->content)
		{
			ft_ra(stack_a);
			tmp[i + 1] = current->content;
		}
		else
			break ;
		current = current->next;
		i++;
	}
	ft_ra(stack_a);
	while (tmp[0] != (*stack_a)->content)
		ft_pb(stack_a, stack_b);
	free(tmp);
}

int	*find_pos(t_int_list **sa, t_int_list **sb)
{
	t_int_list	*tmp;
	t_int_list *tmb = *sb;
	int			*index;
	int			size;
	int			i = 0;
	int			value;
	int			pos;

	size = ft_int_lstsize(*sb);
	index = ft_calloc( size + 1 , sizeof(int));
	while (i < size)
	{
	pos = 0;
	tmp = *sa;
	value = tmb->content;

		while (tmp)
		{
			if (tmp->next == NULL)
			{
				index[i] = pos;
				break ;
			}
			if ((tmp->content < value && tmp->next->content > value) || (value < tmp->content))
			{
				index[i] = pos;
				break ;
			}
		pos++;
		tmp = tmp->next;
		}
	tmb = tmb->next;
	i++;
	}
	return (index);
}
void ft_calculate_moves(t_int_list **sa, t_int_list **sb)
{
    int *index;
    int size_a;
    int size_b;
    int i;
    int moves_a;
    int moves_b;
    int total_moves;
    int best_moves;
    int best_index;
    int best_pos;
    int pos;
    t_int_list *tmp;

    while (ft_int_lstsize(*sb) > 0)
    {
        index = find_pos(sa, sb);
        size_b = ft_int_lstsize(*sb);
        size_a = ft_int_lstsize(*sa);

        best_moves = INT_MAX;
        best_index = -1;
        best_pos = -1;

        i = 0;
        while (i < size_b)
        {
            pos = index[i];

            // Calculate moves for sb
            if (i <= size_b / 2)
                moves_b = i;
            else
                moves_b = size_b - i;

            // Calculate moves for sa
            if (pos <= size_a / 2)
                moves_a = pos;
            else
                moves_a = size_a - pos;

            // Calculate total moves
            total_moves = moves_a + moves_b;
            if (i <= size_b / 2 && pos <= size_a / 2)
                total_moves -= (i < pos) ? i : pos; // Use `rr`
            if (i > size_b / 2 && pos > size_a / 2)
                total_moves -= (size_b - i < size_a - pos) ? size_b - i : size_a - pos; // Use `rrr`

            if (total_moves < best_moves)
            {
                best_moves = total_moves;
                best_index = i;
                best_pos = pos;
            }

            i++;
        }

        // Find the largest element among the elements with the same best_pos
        tmp = *sb;
        i = 0;
        while (i < size_b)
        {
            if (index[i] == best_pos && (i == best_index || tmp->content > (*sb)->content))
            {
                best_index = i;
            }
            tmp = tmp->next;
            i++;
        }

        free(index);

        if (best_index >= 0 && best_pos >= 0)
        {
            // Optimize with `rr` and `rrr`
            while (best_index > 0 && best_index <= size_b / 2 && best_pos > 0 && best_pos <= size_a / 2)
            {
                ft_rr(sa, sb);
                best_index--;
                best_pos--;
            }
            while (best_index > size_b / 2 && best_pos > size_a / 2)
            {
                ft_rrr(sa, sb);
                best_index++;
                best_pos++;
            }

            // Perform moves on sb
            if (best_index <= size_b / 2)
            {
                i = 0;
                while (i < best_index)
                {
                    ft_rb(sb);
                    i++;
                }
            }
            else
            {
                i = 0;
                while (i < size_b - best_index)
                {
                    ft_rrb(sb);
                    i++;
                }
            }

            // Perform moves on sa
            if (best_pos <= size_a / 2)
            {
                i = 0;
                while (i < best_pos)
                {
                    ft_ra(sa);
                    i++;
                }
            }
            else
            {
                i = 0;
                while (i < size_a - best_pos)
                {
                    ft_rra(sa);
                    i++;
                }
            }

            ft_pa(sa, sb); // Push the top of sb to sa
        }
    }
}


int	main(int argc, char **argv)
{
	t_int_list		*stack_a;
	t_int_list		*stack_b;

	if (ft_check_input(argc, argv) == 0)
		stack_a = arg_str_parsing(argv);
	else
		stack_a = arg_list_parsing(argc, argv);
	stack_b = NULL;
	if (ft_small_check(&stack_a, &stack_b, ft_int_lstsize(stack_a)) == 1)
		return (0);
	ft_lis(&stack_a, &stack_b);
	ft_print_stack(stack_a, stack_b);
	ft_calculate_moves(&stack_a, &stack_b);
	ft_print_stack(stack_a, stack_b);
	return (0);
}
