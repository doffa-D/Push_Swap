/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ss_rr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:43:47 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 20:42:33 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(int *stack_a, int *stack_b, int element, int andx)
{
	sa(stack_a, andx);
	sb(stack_b, element, andx);
}

void	rr(int *stack_a, int *stack_b, int andx, int indexb)
{
	if (andx + 1 <= 0 || indexb - 1 <= 0)
		return ;
	ra(stack_a, andx);
	rb(stack_b, indexb);
}

void	rrr(int *stack_a, int *stack_b, int andx, int indexb)
{
	if (andx + 1 <= 0 || indexb - 1 <= 0)
		return ;
	rra(stack_a, andx);
	rrb(stack_b, indexb);
}
