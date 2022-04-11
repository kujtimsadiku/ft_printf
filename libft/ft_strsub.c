/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:17:57 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/02 13:48:56 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*strsub;

	if (!s)
		return (NULL);
	strsub = (char *)malloc(sizeof(char) * len + 1);
	if (!strsub)
		return (NULL);
	i = 0;
	while (len)
	{
		strsub[i] = s[start + i];
		len--;
		i++;
	}
	strsub[i] = '\0';
	return (strsub);
}
