/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:50:39 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/24 11:50:53 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ps1;
	const unsigned char	*ps2;

	i = 0;
	ps1 = s1;
	ps2 = s2;
	while (i < n)
	{
		if (ps1[i] > ps2[i])
			return (ps1[i] - ps2[i]);
		else if (ps1[i] < ps2[i])
			return (ps1[i] - ps2[i]);
		else
			i++;
	}
	return (0);
}
