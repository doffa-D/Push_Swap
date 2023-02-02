/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:43:40 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 19:52:47 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rules_1r(t_data *data, t_count *final)
{
	while (final->ra > 0)
	{
		ra(data->stack_a, data->andx, 2);
		final->ra--;
	}
	while (final->rb > 0)
	{
		rb(data->stack_b, data->element - data->andx - 2, 2);
		final->rb--;
	}
	while (final->rr > 0)
	{
		rr(data->stack_a, data->stack_b,
			data->andx, data->element - data->andx - 2);
		final->rr--;
	}
}

void	move_rules_2r(t_data *data, t_count *final)
{
	while (final->rra > 0)
	{
		rra(data->stack_a, data->andx, 2);
		final->rra--;
	}
	while (final->rrb > 0)
	{
		rrb(data->stack_b, data->element - data->andx - 2, 2);
		final->rrb--;
	}
	while (final->rrr > 0)
	{
		rrr(data->stack_a, data->stack_b,
			data->andx, data->element - data->andx - 2);
		final->rrr--;
	}
}

void	ft_imp(t_data *data, t_count *final)
{
	move_rules_1r(data, final);
	move_rules_2r(data, final);
}

void	best_move(t_data *data)
{
	int	j;

	j = data->element - 3;
	loop(data);
	sort_3(data);
	while (j)
	{
		calculator(data, 0);
		j--;
	}
	push_a(data->stack_a, small(data->stack_a, data->andx), data->andx);
}

void	calculator(t_data *data, int i)
{
	t_count	*struct0;
	t_count	*final;
	int		score;
	int		less;
	int		max_score;

	max_score = INT_MAX;
	score = 0;
	while (i <= data->element - data->andx - 2)
	{
		less = less_than(data->stack_a, data->stack_b[i], data->andx);
		struct0 = count(i, less, data);
		score = ft_get_score(struct0);
		if (score < max_score)
		{
			final = struct0;
			max_score = score;
			data->index_to = i;
			data->less = less;
		}
		i++;
	}
	free(struct0);
	ft_imp(data, final);
	pa(data, data->element, data->andx);
}
