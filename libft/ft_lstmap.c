/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:05:10 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/06 14:03:27 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	head = (*f)(lst);
	if (!head)
		return (NULL);
	head->next = ft_lstmap(lst->next, f);
	return (head);
}
