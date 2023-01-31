/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:18:39 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/30 20:40:18 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void count_stack_a(int andx,t_data *data,int a,t_count *count)
{
	int j;

	j = 0;
	if(andx > a)
	{
		j = data->andx - andx;
		count->ra = j;
	}
	else if(andx <= a)
	{
		j = andx + 1;
		count->rra = j;
	}
}

void count_stack_b(int less,t_data *data,int b,t_count *count)
{
	int j;

	j = 0;
	if(less > b)
	{
		j = (data->element - data->andx - 2) - less;
		count->rb = j;

	}
	else if(less <= b)
	{
		j = less + 1;
		count->rrb = j;
	}
}

t_count	*count(int andx,int less,t_data *data)
{
	int j;
	int a;
	int b;

	a = data->andx / 2;
	b = (data->element - data->andx - 2) / 2;
	j = 0;
	t_count *count;
	count = malloc(sizeof(t_count));
	count->ra = 0;
	count->rb = 0;
	count->rra = 0;
	count->rrb = 0;
	count_stack_a(andx,data,a,count);
	count_stack_b(less,data,b,count);
	return count;
}



