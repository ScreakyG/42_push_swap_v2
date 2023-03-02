/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:46:28 by fgonzale          #+#    #+#             */
/*   Updated: 2023/03/02 03:08:00 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size <= 5 && !is_sorted(*stack_a))
		simple_sort(stack_a, stack_b, stack_size);
	else if (stack_size > 5 && !is_sorted(*stack_a))
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!correct_input(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_numbers(argc, argv);
	stack_size = get_stack_size(stack_a);
	index_numbers(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free(stack_a);
	free(stack_b);
}
