/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:59:12 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/31 14:39:39 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int    check(t_data *data)
{
    if (is_sorted(data->stack_a, data->andx)) 
	{
        ft_printf("array is sorted Erorr\n");
		return 0;
	}
    if(Duplicate(data->stack_a))
    {
        ft_printf("Error Duplicate number\n");
        return 0;
    }
    return 1;
}


int is_sorted(int *stack, int andx) 
{
    int i = 0;
    while (i < andx - 1) 
    {
        if (stack[i] > stack[i + 1]) 
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int Duplicate(int *str)
{
    int i;
    int j;

    j = 0;
    i = 0;

    while(str[i])
    {
        j = j + i + 1;
        printf("%d",str[i]);
        while(str[j])
        {
            if(str[i] == str[j])
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}


char **number_join(t_data *data,char **argv)
{
    int i;
    char *str;
    char **split;

    i = 2;
    str = argv[1];
    while(argv[i])
    {
        str = ft_strjoin(ft_strjoin(str," "),argv[i]);
        i++;
    }
    split = ft_split(str,' ');
    i = 0;
    while(split[i])
        i++;
    data->len = i;
    return split;
}
