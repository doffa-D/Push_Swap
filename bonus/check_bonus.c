/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:59:12 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/04 19:21:51 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error(t_data *data)
{
	write(2, "Error\n", 6);
	free(data->stack_a);
	free(data->stack_b);
	exit(0);
}

int	duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	**number_join(t_data *data, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**split;

	i = 2;
	str = ft_strdup(argv[1]);
	while (argv[i])
	{
		tmp = ft_strjoin(ft_strjoin(str, " "), argv[i]);
		str = tmp;
		i++;
	}
	split = ft_split(str, ' ');
	free(str);
	i = 0;
	while (split[i])
		i++;
	data->len = i;
	return (split);
}
