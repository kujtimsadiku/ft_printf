/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:21:28 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/15 10:55:59 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		len;
	size_t		i;
	char		*f_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	f_str = ft_strnew(len);
	if (!f_str)
		return (NULL);
	i = 0;
	while (len > i)
	{
		f_str[i] = f((char)s[i]);
		i++;
	}
	return (f_str);
}
