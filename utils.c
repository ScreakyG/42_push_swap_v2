/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:52:47 by fgonzale          #+#    #+#             */
/*   Updated: 2023/03/01 01:34:20 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	unsigned int	i;
	long			signe;
	long			resultat;

	resultat = 0;
	signe = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		resultat = (resultat * 10) + (str[i] - '0');
		i++;
	}
	return (resultat * signe);
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	is_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (0);
}

int	get_distance(t_stack *stack_a, int index_min)
{
	int	distance;

	distance = 0;
	while (stack_a)
	{
		if (stack_a->index == index_min)
			return (distance);
		distance++;
		stack_a = stack_a->next;
	}
	return (distance);
}

int	get_min(t_stack *stack_a, int value)
{
	int	min;

	min = stack_a->index;
	while (stack_a)
	{
		if ((stack_a->index < min) && stack_a->index != value)
			min = stack_a->index;
		stack_a = stack_a->next;
	}
	return (min);
}
