/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:51:51 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 20:05:27 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small(int *stack, int len)
{
	int	i;
	int	j;
	int	tmp;

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
	return (j);
}

int	less_than(int *stack, int num, int len)
{
	int		i;
	long	j;
	int		indx;

	i = -1;
	indx = 0;
	j = -1;
	while (++i <= len)
	{
		if (num < stack[i])
		{
			if (j == -1)
			{
				j = (long)stack[i] - (long)num;
				indx = i;
			}
			if ((long)stack[i] - (long)num <= j)
			{
				j = (long)stack[i] - (long)num;
				indx = i;
			}
		}
	}
	return (indx);
}
