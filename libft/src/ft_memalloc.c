/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:34:31 by ksadiku           #+#    #+#             */
/*   Updated: 2021/11/20 18:37:46 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*f_mem;

	f_mem = (void *)malloc(size * sizeof(*f_mem));
	if (f_mem == NULL)
		return (0);
	ft_bzero(f_mem, size);
	return (f_mem);
}
