/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:27:53 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/02 20:04:56 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)malloc(sizeof(t_list));
	if (!fresh)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		fresh->next = NULL;
		return (fresh);
	}
	fresh->content = (void *)malloc(sizeof(content) * content_size);
	if (!fresh->content)
	{
		free(fresh);
		return (fresh);
	}
	ft_memcpy(fresh->content, content, content_size);
	fresh->content_size = content_size;
	fresh->next = NULL;
	return (fresh);
}
