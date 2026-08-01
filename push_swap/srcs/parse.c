/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:03:06 by dosong            #+#    #+#             */
/*   Updated: 2026/07/29 12:16:17 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *str)
{
	return (ft_strncmp(str, "--", 2) == 0);
}

static char	*set_strategy(char *flag)
{
	if (ft_strncmp(flag, "--simple", 9) == 0
		|| ft_strncmp(flag, "--medium", 9) == 0
		|| ft_strncmp(flag, "--complex", 10) == 0
		|| ft_strncmp(flag, "--adaptive", 11) == 0)
		return (flag);
	print_error_and_exit();
	return (NULL);
}

t_stack	*parse(int argc, char **argv, char **strategy)
{
	t_stack	*stack_a;
	int		i;

	*strategy = "--adaptive";
	i = 1;
	if (is_flag(argv[i]))
	{
		*strategy = set_strategy(argv[i]);
		i = 2;
	}
	stack_a = init_stack();
	check_arg(argc - (i - 1), argv + (i - 1), stack_a);
	return (stack_a);
}
