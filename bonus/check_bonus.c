/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:59:12 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/31 22:15:02 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_bonus.h"

int is_sorted(int *stack, int andx) 
{
    int i = 0;
    int j = 0;
    int x = 0;
    while (i < andx) 
    {
        if (stack[i] > stack[i + 1])
            j = 1;
        else
            x = 1;
        i++;
    }
    if(j == 1 && x == 0)
    {
        return 1;
    }
    return 0;
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
        while(str[j])
        {
            if(str[i] == str[j])
            {

                ft_printf("Error Duplicate number\n");
                exit(0);
            }
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
