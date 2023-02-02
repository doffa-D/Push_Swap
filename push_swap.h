/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:03:22 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/02 20:51:34 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct s_count
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rrr;
	int	rr;

}		t_count;

typedef struct s_data
{
	int	argc;
	int	*stack_a;
	int	*stack_b;
	int	element;
	int	andx;
	int	less;
	int	sizeb;
	int	index_to;
	int	len;
}		t_data;

void	sa(int *stack_a, int andx);
void	sb(int *stack_b, int element, int andx);
void	ss(int *stack_a, int *stack_b, int element, int andx);
void	pa(t_data *data, int element, int andx);
void	pb(t_data *data, int element, int andx);
void	ra(int *stack_a, int andx, int num);
void	rb(int *stack_b, int andx, int num);
void	rr(int *stack_a, int *stack_b, int andx, int indexb);
void	rra(int *stack_a, int andx, int num);
void	rrb(int *stack_b, int andx, int num);
void	rrr(int *stack_a, int *stack_b, int andx, int indexb);
void	print(t_data *data);
void	sort_3(t_data *data);
void	sort_5(t_data *data);
void	sort_4(t_data *data);
void	sort_2(t_data *data);
void	push_b(t_data *data, int *stack, int andx, int len);
void	push_a(int *stack, int andx, int len);
int		small(int *stack, int len);
int		less_than(int *stack, int num, int len);

t_count	*count(int andx, int less, t_data *data);

int		big_in_stack(int *stack, int len);
void	best_move(t_data *data);
int		is_sorted(int *stack, int andx);

int		check(t_data *data);
int		duplicate(int *arr, int size);
char	**number_join(t_data *data, char **argv);
void	error(void);

int		ft_get_score_rrr(t_count *struct0);
int		ft_get_score_rr(t_count *struct0);
int		ft_get_score(t_count *struct0);
int		another_sort(t_data *data);
void	range_check(t_data *data);
void	loop(t_data *data);

void	ft_imp(t_data *data, t_count *final);

void	fill(t_data *data, char **argv, int len);
void	final_push(t_data *data);
void	calculator(t_data *data, int i);
void	count_stack_a(int less, t_data *data, int b, t_count *count);
void	count_stack_b(int andx, t_data *data, int a, t_count *count);

int		different_number(char *str);

#endif