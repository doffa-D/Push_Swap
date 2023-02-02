/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:53:57 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 19:49:24 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	another_sort(t_data *data)
{
	int	i;
	int	*tmp;
	int	swp;

	i = -1;
	tmp = malloc(sizeof(int) * data->andx);
	while (++i < data->andx)
		tmp[i] = data->stack_a[i];
	i = -1;
	while (++i < data->andx)
	{
		if (tmp[i] > tmp[i + 1] && i + 1 < data->andx)
		{
			swp = tmp[i];
			tmp[i] = tmp[i + 1];
			tmp[i + 1] = swp;
			i = 0;
		}
	}
	i = tmp[i / 2];
	free(tmp);
	return (i);
}

void	range_check(t_data *data)
{
	int	i;
	int	range;
	int	count;

	count = 0;
	i = data->andx;
	range = another_sort(data);
	while (i > 0)
	{
		if (data->stack_a[i] <= range)
			count++;
		i--;
	}
	while (count && data->andx != 2)
	{
		if (data->stack_a[data->andx] <= range)
		{
			pb(data, data->element, data->andx);
			count--;
		}
		else
			ra(data->stack_a, data->andx, 2);
		i--;
	}
}

void	loop(t_data *data)
{
	int	i;

	i = 0;
	while (data->andx != 2)
		range_check(data);
}
