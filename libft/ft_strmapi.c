/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:19:15 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/12 15:13:41 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*f_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	f_str = ft_strnew(len);
	if (!f_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		f_str[i] = (*f)(i, (char)s[i]);
		i++;
	}
	return (f_str);
}
