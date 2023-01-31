/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:39:57 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/30 20:40:18 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_get_score_rr(t_count *struct0)
{
	int score;
	score = 0;

	if(struct0->ra == struct0->rb)
	{
		struct0->rr = struct0->ra;
		struct0->ra = 0;
		struct0->rb = 0;
	}
	else if(struct0->ra > struct0->rb)
	{
		struct0->rr = struct0->rb;
		struct0->ra = struct0->ra - struct0->rb;
		struct0->rb = 0;
	}
	else if(struct0->ra < struct0->rb)
	{
		struct0->rr = struct0->ra;
		struct0->rb = struct0->rb - struct0->ra;
		struct0->ra = 0;
	}
	score = struct0->rr + struct0->ra + struct0->rb;
	return score;
}

int ft_get_score_rrr(t_count *struct0)
{
	int score;
	score = 0;

	if(struct0->rra == struct0->rrb)
	{
		struct0->rrr = struct0->rra;
		struct0->rra = 0;
		struct0->rrb = 0;
	}
	else if(struct0->rra > struct0->rrb)
	{
		struct0->rrr = struct0->rrb;
		struct0->rra = struct0->rra - struct0->rrb;
		struct0->rrb = 0;
	}
	else if(struct0->rra < struct0->rrb)
	{
		struct0->rrr = struct0->rra;
		struct0->rrb = struct0->rrb - struct0->rra;
		struct0->rra = 0;
		
	}
	score = struct0->rrr + struct0->rra + struct0->rrb;
	return score;
}

int ft_get_score(t_count *struct0)
{
	int final;
	final = ft_get_score_rrr(struct0) + ft_get_score_rr(struct0);
	return final;
}