/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_sa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:50:49 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/31 23:26:58 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void sa(int *stack_a,int andx)
{
	int tmp;
	if(andx <= 0)
		return ;
	tmp= stack_a[andx - 1];
	stack_a[andx - 1] = stack_a[andx];
	stack_a[andx] = tmp;
}


void pa(t_data *data, int element, int andx)
{
	data->stack_a[andx + 1] = data->stack_b[element - andx - 2];
	data->stack_b[element - andx - 2] = 0;
	data->sizeb--;
	data->andx++;
}

void ra(int *stack_a, int andx)
{
	int y;
	int i = andx;
	y = stack_a[andx];
	while(i)
	{
		stack_a[i] = stack_a[i-1];
		i--;
	}
	stack_a[i] = y;
}

void rra(int *stack_a, int andx)
{
	int y;
	int i = 0;
	y = stack_a[0];
	while(i < andx)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = y;
}
