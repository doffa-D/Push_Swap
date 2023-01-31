/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:51:51 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/30 20:14:13 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int small(int *stack, int len)
{
	int i;
	int j;
	int tmp;

	tmp = stack[len];
	i = 0;
	j = len;
	while (i < len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			j = i;
		}
		i++;
	}
	return j;
}

int big_in_stack(int *stack, int len)
{
	int tmp;
	int i;
	int andx;

	i = 0;
	tmp = stack[i];
	andx = 0;

	while (i <= len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			andx = i;
		}
		i++;
	}
	return andx;
}

int	less_than(int *stack,int num,int len)
{
	int i;
	long j;
	int indx;
	
	i = -1;
	indx = 0;
	j = -1;
	while(++i <= len)
	{
		if(num > stack[i])
		{
			if(j == -1)
			{
				j = (long)num - (long)stack[i];
				indx = i;
			}
			if((long)num - (long)stack[i] <= j)
			{
				j = (long)num - (long)stack[i];
				indx = i;
			}
		}
	}
	if(j != -1)
		return indx;
	return(big_in_stack(stack,len));
}