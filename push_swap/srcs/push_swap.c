/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:00:11 by dosong            #+#    #+#             */
/*   Updated: 2026/08/06 16:51:30 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strategy(char *strategy, char *name)
{
	if (!strategy)
		return (0);
	return (ft_strncmp(strategy, name, ft_strlen(name) + 1) == 0);
}

static void	sort_disorder(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	if (!bench->is_bench)
		bench->disorder = compute_disorder(stack_a);
	if (bench->disorder < 20)
	{
		bench->strategy = "Simple";
		bench->complexity = "O(n^2)";
		sort_simple(stack_a, stack_b);
	}
	else if (bench->disorder < 50)
	{
		bench->strategy = "Medium";
		bench->complexity = "O(n sqrt n)";
		sort_medium(stack_a, stack_b);
	}
	else
	{
		bench->strategy = "Complex";
		bench->complexity = "O(n log n)";
		sort_complex(stack_a, stack_b);
	}
}

static void	sort_stack(t_stack *stack_a, t_stack *stack_b, \
	char *strategy, t_bench *bench)
{
	if (is_strategy(strategy, "--simple"))
	{
		bench->strategy = "Simple";
		bench->complexity = "O(n^2)";
		sort_simple(stack_a, stack_b);
	}
	else if (is_strategy(strategy, "--medium"))
	{
		bench->strategy = "Medium";
		bench->complexity = "O(n sqrt n)";
		sort_medium(stack_a, stack_b);
	}
	else if (is_strategy(strategy, "--complex"))
	{
		bench->strategy = "Complex";
		bench->complexity = "O(n log n)";
		sort_complex(stack_a, stack_b);
	}
	else
		sort_disorder(stack_a, stack_b, bench);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*strategy;
	t_bench	bench;

	if (ac < 2)
		return (0);
	ft_bzero(&bench, sizeof(t_bench));
	bench.is_bench = check_bench_flag(ac, av);
	stack_a = parse(ac, av, &strategy);
	stack_b = init_stack();
	if (!stack_b)
		print_error_and_exit(stack_a, NULL);
	stack_a->bench = &bench;
	stack_b->bench = &bench;
	if (bench.is_bench)
		bench.disorder = compute_disorder(stack_a);
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b, strategy, &bench);
	print_bench_stats(&bench);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
