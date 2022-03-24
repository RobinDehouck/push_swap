/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:36:05 by robindehouc       #+#    #+#             */
/*   Updated: 2022/03/24 13:57:40 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_putnumber(const char *source, int i)
{
	int		j;
	long	number;

	j = 0;
	number = 0;
	while (source[i] >= '0' && source[i] <= '9')
	{
		number = number * 10 + source[i] - '0';
		i++;
	}
	return (number);
}

static int	ft_clean(const char *source)
{
	int	i;

	i = 0;
	while ((source[i] >= 9 && source[i] <= 13) || source[i] == 32)
	{
		i++;
	}
	return (i);
}

long	ft_atoi(const char *number)
{
	int		sign;
	int		i;
	long	final_number;

	sign = 1;
	i = ft_clean(number);
	if (number[i] == '+')
		i++;
	else if (number[i] == '-')
	{
		i++;
		sign *= -1;
	}
	final_number = ft_putnumber(number, i);
	return (final_number * sign);
}
