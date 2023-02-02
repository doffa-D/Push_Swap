/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:50:49 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 20:13:56 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(int *stack_b, int element, int andx)
{
	int	tmp;

	tmp = stack_b[element - andx - 3];
	stack_b[element - andx - 3] = stack_b[element - andx - 2];
	stack_b[element - andx - 2] = tmp;
	ft_printf("sb\n");
}

void	pb(t_data *data, int element, int andx)
{
	data->stack_b[element - andx - 1] = data->stack_a[andx];
	data->stack_a[andx] = 0;
	data->andx--;
	data->sizeb++;
	ft_printf("pb\n");
}

void	rb(int *stack_b, int andx, int num)
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
	if (num != 1)
		ft_printf("rb\n");
}

void	rrb(int *stack_b, int andx, int num)
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
	if (num != 1)
		ft_printf("rrb\n");
}
