/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:48:01 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 20:16:27 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	sort_2(t_data *data)
{
	if (data->stack_a[0] < data->stack_a[1])
		sa(data->stack_a, data->andx);
}

void	sort_3(t_data *data)
{
	int	i;
	int	*s_a;

	i = data->andx;
	s_a = data->stack_a;
	if (s_a[i] > s_a[i - 1] && s_a[i - 2] > s_a[i] && s_a[i - 1] < s_a[i - 2])
		sa(s_a, i);
	if (s_a[i] > s_a[i - 1] && s_a[i] > s_a[i - 2] && s_a[i - 2] > s_a[i - 1])
		ra(s_a, i, 2);
	if (s_a[i] < s_a[i - 1] && s_a[i] > s_a[i - 2] && s_a[i - 1] > s_a[i - 2])
		rra(s_a, i, 2);
	if (s_a[i] > s_a[i - 1] && s_a[i] > s_a[i - 2] && s_a[i - 1] > s_a[i - 2])
	{
		sa(s_a, i);
		rra(s_a, i, 2);
	}
	if (s_a[i] < s_a[i - 1] && s_a[i] < s_a[i - 2] && s_a[i - 1] > s_a[i - 2])
	{
		sa(s_a, i);
		ra(s_a, i, 2);
	}
}

void	sort_4(t_data *data)
{
	int	i;
	int	j;

	j = data->andx;
	i = 0;
	while (i < 1)
	{
		push_a(data->stack_a, small(data->stack_a, data->andx), data->andx);
		pb(data, data->element, data->andx);
		i++;
	}
	sort_3(data);
	pa(data, data->element, data->andx);
}

void	sort_5(t_data *data)
{
	int	i;
	int	j;

	j = data->andx;
	i = 0;
	while (i < 2)
	{
		push_a(data->stack_a, small(data->stack_a, data->andx), data->andx);
		pb(data, data->element, data->andx);
		i++;
	}
	sort_3(data);
	pa(data, data->element, data->andx);
	pa(data, data->element, data->andx);
}
