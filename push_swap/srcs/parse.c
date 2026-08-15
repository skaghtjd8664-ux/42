/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:03:06 by dosong            #+#    #+#             */
/*   Updated: 2026/08/05 11:11:34 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bench_flag(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	is_strategy_flag(char *flag)
{
	return (ft_strncmp(flag, "--simple", 9) == 0 \
			|| ft_strncmp(flag, "--medium", 9) == 0 \
			|| ft_strncmp(flag, "--complex", 10) == 0 \
			|| ft_strncmp(flag, "--adaptive", 11) == 0);
}

t_stack	*parse(int argc, char **argv, char **strategy)
{
	t_stack	*stack_a;
	int		i;

	*strategy = "--adaptive";
	i = 1;
	while (i < argc && (is_strategy_flag(argv[i]) || \
			ft_strncmp(argv[i], "--bench", 8) == 0))
	{
		if (is_strategy_flag(argv[i]))
			*strategy = argv[i];
		i++;
	}
	stack_a = init_stack();
	if (!stack_a)
		print_error_and_exit(NULL, NULL);
	check_arg(argc - (i - 1), argv + (i - 1), stack_a);
	return (stack_a);
}
