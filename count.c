/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:18:39 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/04 16:56:31 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_stack_b(int andx, t_data *data, int b, t_count *count)
{
	int	j;

	j = 0;
	if (andx > b)
	{
		j = (data->element - data->andx - 2) - andx;
		count->rb = j;
	}
	else if (andx <= b)
	{
		j = andx + 1;
		count->rrb = j;
	}
}

void	count_stack_a(int less, t_data *data, int a, t_count *count)
{
	int	j;

	j = 0;
	if (less > a)
	{
		j = data->andx - less;
		count->ra = j;
	}
	else if (less <= a)
	{
		j = less + 1;
		count->rra = j;
	}
}

t_count	count(int andx, int less, t_data *data)
{
	t_count	count;
	int		j;
	int		a;
	int		b;

	a = data->andx / 2;
	b = (data->element - data->andx - 2) / 2;
	j = 0;
	count.ra = 0;
	count.rb = 0;
	count.rra = 0;
	count.rrb = 0;
	count_stack_b(andx, data, b, &count);
	count_stack_a(less, data, a, &count);
	return (count);
}
