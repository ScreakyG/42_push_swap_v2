/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:41:58 by fgonzale          #+#    #+#             */
/*   Updated: 2023/02/27 22:58:20 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_numbers(t_stack *stack_a, int stack_size)
{
	t_stack	*tmp;
	t_stack	*highest_number_pointer;
	int		highest_number;

	while (--stack_size > 0)
	{
		tmp = stack_a;
		highest_number_pointer = NULL;
		highest_number = INT_MIN;
		while (tmp)
		{
			if (tmp->nb == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->nb > highest_number && tmp->index == 0)
			{
				highest_number = tmp->nb;
				highest_number_pointer = tmp;
				tmp = stack_a;
			}
			else
				tmp = tmp->next;
		}
		if (highest_number_pointer != NULL)
			highest_number_pointer->index = stack_size;
	}
}

t_stack	*fill_stack_numbers(int argc, char **argv)
{
	t_stack	*stack_a;
	long	nb;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			exit_error(&stack_a, NULL);
		stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
