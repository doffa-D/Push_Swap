/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_sb_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:50:49 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 20:42:21 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(int *stack_b, int element, int andx)
{
	int	tmp;

	if (element - andx - 2 <= 0)
		return ;
	tmp = stack_b[element - andx - 3];
	stack_b[element - andx - 3] = stack_b[element - andx - 2];
	stack_b[element - andx - 2] = tmp;
}

void	pb(t_data *data, int element, int andx)
{
	if (data->andx + 1 == 0)
		return ;
	data->stack_b[element - andx - 1] = data->stack_a[andx];
	data->stack_a[andx] = 0;
	data->andx--;
	data->sizeb++;
}

void	rb(int *stack_b, int andx)
{
	int	y;
	int	i;

	i = andx;
	y = stack_b[andx];
	while (i)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[i] = y;
}

void	rrb(int *stack_b, int andx)
{
	int	y;
	int	i;

	i = 0;
	y = stack_b[0];
	while (i < andx)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = y;
}
