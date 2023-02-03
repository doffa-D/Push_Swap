/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:32:55 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/03 18:54:02 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error3(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

long long int	ft_atoi(const char *str, int i)
{
	int					sign;
	unsigned long long	number;

	number = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			number = number * 10 + str[i] - '0';
		else if (str[i] != ' ')
			error3();
		i++;
	}
	return (number * sign);
}
