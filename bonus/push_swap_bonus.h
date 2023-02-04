/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:07:06 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/04 15:54:20 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>

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

char	*get_next_line(int fd);
void	sa(int *stack_a, int andx);
void	sb(int *stack_b, int element, int andx);
void	ss(int *stack_a, int *stack_b, int element, int andx);
void	pa(t_data *data, int element, int andx);
void	pb(t_data *data, int element, int andx);
void	ra(int *stack_a, int andx);
void	rb(int *stack_b, int andx);
void	rr(int *stack_a, int *stack_b, int andx, int indexb);
void	rra(int *stack_a, int andx);
void	rrb(int *stack_b, int andx);
void	rrr(int *stack_a, int *stack_b, int andx, int indexb);
void	fill(t_data *data, char **str, int len);
int		checker(char *str, t_data *data);
int		is_sorted(int *stack, int andx);
char	**number_join(t_data *data, char **argv);
int		duplicate(int *arr, int size);
void	error(t_data *data);
#endif