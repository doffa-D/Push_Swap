/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_sa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:50:49 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 20:13:42 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack_a, int andx)
{
	int	tmp;

	if (andx <= 0)
		return ;
	tmp = stack_a[andx - 1];
	stack_a[andx - 1] = stack_a[andx];
	stack_a[andx] = tmp;
	ft_printf("sa\n");
}

void	pa(t_data *data, int element, int andx)
{
	data->stack_a[andx + 1] = data->stack_b[element - andx - 2];
	data->stack_b[element - andx - 2] = 0;
	data->sizeb--;
	data->andx++;
	ft_printf("pa\n");
}

void	ra(int *stack_a, int andx, int num)
{
	int	y;
	int	i;

	i = andx;
	y = stack_a[andx];
	while (i)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[i] = y;
	if (num != 1)
		ft_printf("ra\n");
}

void	rra(int *stack_a, int andx, int num)
{
	int	y;
	int	i;

	i = 0;
	y = stack_a[0];
	while (i < andx)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = y;
	if (num != 1)
		ft_printf("rra\n");
}
