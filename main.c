/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:34:09 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/31 20:01:30 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill(t_data *data, char **str, int len)
{
	int i = 0;

	data->stack_a = malloc(sizeof(int) * len);
	data->stack_b = malloc(sizeof(int) * len);
	if (!data->stack_a || !data->stack_b)
		return ;
	while(i < len)
	{
		data->stack_a[i] = ft_atoi(str[len - i - 1]);
		data->stack_b[i] = 0;
		i++;
	}
	Duplicate(data->stack_a);
	data->element = i;
	data->andx = i - 1;
	data->argc = len;


}

int main(int argc, char *argv[])
{
	t_data data;

	if(argc == 1 || !argv[2])
	{
		ft_printf("Error\n");
		exit(0);
	}
	if(argc != 2)
	{
		fill(&data, number_join(&data,argv), data.len);
		is_sorted(data.stack_a,data.andx);
		if (argc == 3)
			sort_2(&data);
		else if (argc == 4)
			sort_3(&data);
		else if (argc == 5)
			sort_4(&data);
		else if (argc == 6)
			sort_5(&data);
		else if(argc > 6)
			best_move(&data);
		// print(&data);
	}
	return 0;
}
