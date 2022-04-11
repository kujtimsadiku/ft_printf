/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:42:58 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/02 12:28:41 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
	{
		new = (void *)malloc(sizeof(*ptr) * (size + 1));
		if (!new)
			return (NULL);
	}
	else
	{
		new = (void *)malloc(sizeof(*ptr) * (size + 1));
		if (!new)
			return (NULL);
		ft_memcpy(new, ptr, ft_strlen(ptr));
		free(ptr);
	}
	return (new);
}
