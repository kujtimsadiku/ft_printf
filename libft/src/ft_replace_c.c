/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:47:05 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/30 12:00:19 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_c(char *str, char find, char replace)
{
	char	*mod;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	if (!str)
		return (NULL);
	mod = (char *)malloc(sizeof(char) * (len + 1));
	if (!mod)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == find)
			mod[i] = replace;
		else
			mod[i] = str[i];
		i++;
	}
	mod[i] = '\0';
	return (mod);
}
