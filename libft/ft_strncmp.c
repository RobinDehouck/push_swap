/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:02:51 by rdehouck          #+#    #+#             */
/*   Updated: 2022/03/23 14:26:02 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *source1, const char *source2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (source1[i] && i < n - 1)
	{
		if (source1[i] != source2[i])
			return ((unsigned char) source1[i] - (unsigned char) source2[i]);
		i++;
	}
	return ((unsigned char) source1[i] - (unsigned char) source2[i]);
}
