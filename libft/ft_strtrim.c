/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:57:47 by robindehouc       #+#    #+#             */
/*   Updated: 2022/03/23 14:26:15 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_suffix(const char *source, char const *set, int start)
{
	int	i;
	int	j;
	int	count;

	i = ft_strlen(source) - 1;
	j = 0;
	while (set[j])
	{
		count = 0;
		if (set[j] == source[i] && i >= start)
		{
			i--;
			count++;
			j = 0;
		}
		if (count == 0)
			j++;
	}
	return (i);
}

static int	ft_prefix(const char *source, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (set[j])
	{
		count = 0;
		if (set[j] == source[i])
		{
			i++;
			count++;
			j = 0;
		}
		if (count == 0)
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *source, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	if (!source)
		return (NULL);
	i = 0;
	start = ft_prefix(source, set);
	end = ft_suffix(source, set, start);
	trimmed = malloc(sizeof(char) * ft_strlen(source) + 1);
	if (trimmed == NULL)
		return (NULL);
	while (start <= end)
	{
		trimmed[i] = source[start];
		i++;
		start++;
	}
	trimmed[i] = 0;
	return (trimmed);
}
