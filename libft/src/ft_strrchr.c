/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:21:56 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/22 18:07:20 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*found;
	size_t		i;

	found = NULL;
	i = ft_strlen(s) + 1;
	while (i)
	{
		if (*s == (char)c)
			found = ft_strchr(s, c);
		s++;
		i--;
	}
	return ((char *)found);
}
