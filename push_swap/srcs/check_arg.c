/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:03:04 by honam             #+#    #+#             */
/*   Updated: 2026/07/28 13:11:56 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *stack_a, int num)
{
	t_node	*current;

	if (!stack_a || !stack_a->head)
		return (0);
	current = stack_a->head;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
		if (current == stack_a->head)
			break ;
	}
	return (0);
}

int	check_num(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		print_error_and_exit();
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long long	check_overflow(const char *str)
{
	int			i;
	int			sign;
	long long	value;

	i = 0;
	sign = 1;
	value = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		value *= 10;
		value += (str[i] - '0');
		i++;
		if (value > INT_MAX || value < INT_MIN)
			print_error_and_exit();
	}
	return (value * sign);
}

void	check_arg(int argc, char **argv, t_stack *stack_a)
{
	char		**split_str;
	int			i;
	int			j;
	long long	num;

	i = 1;
	while (i < argc)
	{
		split_str = ft_split(argv[i], ' ');
		j = 0;
		while (split_str[j])
		{
			if (!check_num(split_str[j]))
				print_error_and_exit();
			num = check_overflow(split_str[j]);
			if (check_duplicate(stack_a, (int)num))
				print_error_and_exit();
			add_last(stack_a, create_node((int)num));
			j++;
		}
		i++;
	}
}
