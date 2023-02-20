/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:06:24 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/23 18:03:17 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*dst;

	dst = b;
	if (!len)
		return (b);
	while (len--)
	{
		*dst = (unsigned char)c;
		dst++;
	}	
	return (b);
}
