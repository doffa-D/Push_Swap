/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:32:55 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/31 14:29:54 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sing;

	result = 0;
	sing = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = -1;
		i++;
	}
	while (str[i])
	{
		if(ft_isdigit(str[i]))
			result = (result * 10) + str[i] - 48;
		else
		{
			ft_printf("You have a wrong number\n");
			exit(0);
		}
		i++;
	}
	return (result * sing);
}
