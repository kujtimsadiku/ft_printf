/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:05:14 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/02 20:06:55 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s)
		return (NULL);
	while (ft_space(s[start]))
		start++;
	end = ft_strlen(s);
	while ((s[end] == '\0' || ft_space(s[end])) && end != start)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
