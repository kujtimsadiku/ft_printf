/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:13:19 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/24 16:56:41 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;
	size_t				i;

	pdst = dst;
	psrc = src;
	i = 1;
	if (dst > src)
	{
		while (len >= i)
		{
			pdst[len - i] = psrc[len - i];
			i++;
		}
		return (pdst);
	}
	return (ft_memcpy(pdst, psrc, len));
}
