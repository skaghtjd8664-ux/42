/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:00:11 by dosong            #+#    #+#             */
/*   Updated: 2026/07/29 10:51:21 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strategy(char *strategy, char *name)
{
	if (!strategy)
		return (0);
	return (ft_strncmp(strategy, name, ft_strlen(name) + 1) == 0);
}

static void	sort_by_disorder(t_stack *stack_a, t_stack *stack_b,
	double disorder)
{
	if (disorder < 0.2)
		sort_simple(stack_a, stack_b);
	else if (disorder < 0.5)
		sort_medium(stack_a, stack_b);
	else
		sort_complex(stack_a, stack_b);
}

static void	sort_stack(t_stack *stack_a, t_stack *stack_b, char *strategy)
{
	if (is_strategy(strategy, "--simple"))
		sort_simple(stack_a, stack_b);
	else if (is_strategy(strategy, "--medium"))
		sort_medium(stack_a, stack_b);
	else if (is_strategy(strategy, "--complex"))
		sort_complex(stack_a, stack_b);
	else
		sort_by_disorder(stack_a, stack_b, compute_disorder(stack_a));
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*strategy;

	if (ac < 2)
		return (0);
	stack_a = parse(ac, av, &strategy);
	stack_b = init_stack();
	if (is_sorted(stack_a))
		return (0);
	sort_stack(stack_a, stack_b, strategy);
	return (0);
}
