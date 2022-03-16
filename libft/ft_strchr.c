/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:44:33 by rdehouck          #+#    #+#             */
/*   Updated: 2022/02/08 11:52:22 by rdehouck         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *source, int c)
{
	int		i;
	char	*located;

	if (!source)
		return (0);
	located = (char *)source;
	i = 0;
	if ((char) c == 0)
	{
		while (located[i])
			i++;
		return (&located[i]);
	}
	while (located[i])
	{
		if (located[i] == (char)c)
			return (&located[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char *test = "bonjour";
	printf("moi :%s", ft_strchr(test, 'o' + 256));
	printf("\ntst :%s", strchr(test, 'o' + 256));
}*/