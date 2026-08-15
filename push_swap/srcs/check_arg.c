/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:03:04 by honam             #+#    #+#             */
/*   Updated: 2026/08/05 11:16:01 by dosong           ###   ########.fr       */
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
		return (0);
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
		if (value * sign > INT_MAX || value * sign < INT_MIN)
			return (2147483649LL);
	}
	return (value * sign);
}

static void	process_split_args(char **split_str, t_stack *stack_a)
{
	int			j;
	long long	num;
	t_node		*new_node;

	j = 0;
	while (split_str[j])
	{
		if (!check_num(split_str[j]))
			print_error_and_exit(stack_a, split_str);
		num = check_overflow(split_str[j]);
		if (num > INT_MAX || num < INT_MIN)
			print_error_and_exit(stack_a, split_str);
		if (check_duplicate(stack_a, (int)num))
			print_error_and_exit(stack_a, split_str);
		new_node = create_node((int)num);
		if (!new_node)
			print_error_and_exit(stack_a, split_str);
		add_last(stack_a, new_node);
		j++;
	}
}

void	check_arg(int argc, char **argv, t_stack *stack_a)
{
	char		**split_str;
	int			i;

	i = 1;
	while (i < argc)
	{
		split_str = ft_split(argv[i], ' ');
		if (!split_str || !split_str[0])
			print_error_and_exit(stack_a, split_str);
		process_split_args(split_str, stack_a);
		free_split(split_str);
		i++;
	}
}
