/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:58:31 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 20:11:32 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_data *data, int *stack, int andx, int len)
{
	int	j;
	int	i;

	j = 0;
	i = len / 2;
	if (andx == data->sizeb)
		return ;
	if (andx >= i)
	{
		while (len != andx)
		{
			rb(stack, len, 2);
			j++;
			andx++;
		}
	}
	else if (andx < i)
	{
		while (len != andx)
		{
			rrb(stack, len, 2);
			andx--;
			andx = (andx + len + 1) % (len + 1);
		}
	}
}

void	push_a(int *stack, int andx, int len)
{
	int	j;
	int	i;

	j = 0;
	i = len / 2;
	if (andx == len)
		return ;
	if (andx >= i)
	{
		while (len != andx)
		{
			ra(stack, len, 2);
			j++;
			andx++;
		}
	}
	else if (andx < i)
	{
		while (len != andx)
		{
			rra(stack, len, 2);
			andx--;
			andx = (andx + len + 1) % (len + 1);
		}
	}
}
