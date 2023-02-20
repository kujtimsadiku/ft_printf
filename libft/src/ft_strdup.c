/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:33:20 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/11 12:15:51 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int				i;
	size_t			len;
	char			*ps1;

	i = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	ps1 = (char *)malloc(sizeof(char) * (len + 1));
	if (ps1 == NULL)
		return (0);
	while (0 < len)
	{
		ps1[i] = s1[i];
		i++;
		len--;
	}
	ps1[i] = '\0';
	return (ps1);
}
