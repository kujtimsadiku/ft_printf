/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:05:49 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/16 13:13:24 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*fresh;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fresh = ft_memalloc(sizeof(*fresh) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!fresh)
		return (NULL);
	i = 0;
	while (*s1)
	{
		fresh[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		fresh[i] = *s2++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
