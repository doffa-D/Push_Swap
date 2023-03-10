/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:13:51 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/09 11:42:52 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	if (data->len == 1)
		exit(0);
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
}

int	checker(char *str, t_data *data)
{
	if (ft_strncmp("ra\n", str, 3) == 0 && ft_strlen(str) == 3)
		ra(data->stack_a, data->andx);
	else if (ft_strncmp("rb\n", str, 3) == 0 && ft_strlen(str) == 3)
		rb(data->stack_b, data->element - data->andx - 2);
	else if (ft_strncmp("rr\n", str, 3) == 0 && ft_strlen(str) == 3)
		rr(data->stack_a, data->stack_b, data->andx, data->element - data->andx
			- 2);
	else if (ft_strncmp("rra\n", str, 4) == 0 && ft_strlen(str) == 4)
		rra(data->stack_a, data->andx);
	else if (ft_strncmp("rrb\n", str, 4) == 0 && ft_strlen(str) == 4)
		rrb(data->stack_b, data->element - data->andx - 2);
	else if (ft_strncmp("rrr\n", str, 4) == 0 && ft_strlen(str) == 4)
		rrr(data->stack_a, data->stack_b, data->andx, data->element - data->andx
			- 2);
	else if (ft_strncmp("sa\n", str, 3) == 0 && ft_strlen(str) == 3)
		sa(data->stack_a, data->andx);
	else if (ft_strncmp("sb\n", str, 3) == 0 && ft_strlen(str) == 3)
		sb(data->stack_b, data->element, data->andx);
	else if (ft_strncmp("pb\n", str, 3) == 0 && ft_strlen(str) == 3)
		pb(data, data->element, data->andx);
	else if (ft_strncmp("pa\n", str, 3) == 0 && ft_strlen(str) == 3)
		pa(data, data->element, data->andx);
	else
		return (0);
	return (1);
}

void	check_sort(t_data *data)
{
	int	i;

	if (data->element != data->andx + 1)
	{
		ft_printf("%sKO\n", "\033[0;31m");
		return ;
	}
	i = 0;
	while (i <= data->andx - 1)
	{
		if (data->stack_a[i] < data->stack_a[i + 1])
		{
			ft_printf("%sKO\n", "\033[0;31m");
			return ;
		}
		i++;
	}
	ft_printf("%sOK\n", "\033[0;32m");
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*str;
	int		v;
	char	**splited;

	v = 1;
	if (argc == 1)
		exit(0);
	no_thing(argv, &data);
	splited = number_join(&data, argv);
	check_max(splited, &data);
	fill(&data, splited, data.len);
	while (v)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!checker(str, &data))
			error(&data);
		free(str);
	}
	check_sort(&data);
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}
