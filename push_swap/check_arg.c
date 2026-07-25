/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:03:04 by honam             #+#    #+#             */
/*   Updated: 2026/07/25 17:57:02 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(int *arr)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i] != '\0')
	{
		while (temp[j] != '\0')
		{
			if (arr[i] == temp[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_num(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		print_error_and_exit("Error\n");
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse(int argc, char **argv)
{
	int		i;
	char	**split_str;
	t_node	*temp;

	split_str = ft_split(argv, ' ');
	i = 0;
	while (i < argc)
	{
		temp->value = ft_atoi(split_str[i]);
		if (!ft_isdigit(temp->value))
			print_error_and_exit("Error\n");
		i++;
	}
	if ()
	return (temp);
}
