/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:13:51 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/31 23:45:11 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmpw(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
		if (i == n)
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


void print(t_data *data)
{
	int i = 0;
	ft_printf("-----------------------------------------\n");
	while (i < data->element)
	{
		ft_printf("|\t%d [%d] \t\t|\t%d [%d]\t|\n", data->stack_a[i],i, data->stack_b[i],i);
		i++;
	}
	ft_printf("|\n--------|  A  |--------------|  B  |-----\n");

}


void fill(t_data *data, char **str, int len)
{
	int i = 0;

	data->stack_a = malloc(sizeof(int) * len);
	data->stack_b = malloc(sizeof(int) * len);
	if (!data->stack_a || !data->stack_b)
		return ;
	while(i < len)
	{
		data->stack_a[i] = ft_atoi(str[i]);
		data->stack_b[i] = 0;
		i++;
	}
	Duplicate(data->stack_a);
	data->element = i;
	data->andx = i - 1;

}

int checker(char *str,t_data *data)
{
	if(ft_strncmp("ra\n",str,3) == 0)
		ra(data->stack_a,data->andx);
	else if(ft_strncmp("rb\n",str,3) == 0)
		rb(data->stack_b,data->element - data->andx - 2);
	else if(ft_strncmp("rr\n",str,3) == 0)
		rr(data->stack_a,data->stack_b,data->andx,data->element - data->andx - 2);
	else if(ft_strncmp("rra\n",str,4) == 0)
		rra(data->stack_a,data->andx);
	else if(ft_strncmp("rrb\n",str,4) == 0)
		rrb(data->stack_b,data->element - data->andx - 2);
	else if(ft_strncmp("rrr\n",str,4) == 0)
		rrr(data->stack_a,data->stack_b,data->andx,data->element - data->andx - 2);
	else if(ft_strncmp("sa\n",str,3) == 0)
		sa(data->stack_a,data->andx);
	else if(ft_strncmp("sb\n",str,3) == 0)
		sb(data->stack_b,data->element, data->andx);
	else if(ft_strncmp("pb\n",str,3) == 0)
		pb(data,data->element,data->element - data->andx - 2);
	else if(ft_strncmp("pa\n",str,3) == 0)
		pa(data,data->element,data->andx);
	// print(data);
	ft_printf("str: %s",str);
	return 0;
}

int main(int argc,char **argv)
{
	t_data data;
	char *str;

	if(argc == 1 || !argv[2])
	{
		ft_printf("Error\n");
		exit(0);
	}
	(void)str;
	fill(&data, number_join(&data,argv), data.len);
	while(1 && (str = get_next_line(0)))
	{
		checker(str,&data);
	print(&data);

	}
	if(is_sorted(data.stack_a,data.andx) == 0)
	{
		write(1,"KO\n",3);
	}
	else
		write(1,"OK\n",3);
	return 0;
}
// pb ra pb ra sa ra pa pa