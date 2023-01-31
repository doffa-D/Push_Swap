/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_ss_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:43:47 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/30 20:44:24 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int *stack_a,int *stack_b, int element,int andx)
{
	sa(stack_a,andx);
	sb(stack_b,element,andx);
	ft_printf("ss\n");
}



void rr(int *stack_a,int *stack_b, int andx,int indexb)
{
	ra(stack_a,andx,1);
	rb(stack_b,indexb,1);
	ft_printf("rr\n");
}


void rrr(int *stack_a,int *stack_b, int andx,int indexb)
{
	rra(stack_a,andx,1);
	rrb(stack_b,indexb,1);
	ft_printf("rrr\n");
}
