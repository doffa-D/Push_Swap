/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:34:09 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/04 19:21:07 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i], 0) > INT_MAX || ft_atoi(argv[i], 0) < INT_MIN)
			error(data);
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
				|| (argv[i][j] == '+' && !ft_isdigit(argv[i][j + 1]))
				|| (argv[i][j] == '-' && argv[i][j + 1] == '-'))
				error(data);
			j++;
		}
		i++;
	}
}

void	fill(t_data *data, char **str, int len)
{
	int	i;

	i = 0;
	data->stack_a = malloc(sizeof(int) * len);
	data->stack_b = malloc(sizeof(int) * len);
	if (!data->stack_a || !data->stack_b)
		return ;
	while (i < len)
	{
		data->stack_a[i] = ft_atoi(str[len - i - 1], 0);
		free(str[len - i - 1]);
		data->stack_b[i] = 0;
		i++;
	}
	free(str);
	duplicate(data->stack_a, len);
	data->element = i;
	data->andx = i - 1;
	data->argc = len;
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	**splited;

	if (argc == 1)
		exit(0);
	splited = number_join(&data, argv);
	check_max(splited, &data);
	fill(&data, splited, data.len);
	is_sorted(&data);
	if (data.len == 2)
		sort_2(&data);
	else if (data.len == 3)
		sort_3(&data);
	else if (data.len == 4)
		sort_4(&data);
	else if (data.len == 5)
		sort_5(&data);
	else if (data.len > 5)
		best_move(&data);
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}
