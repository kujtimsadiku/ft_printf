/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:39:22 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/02 20:07:15 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*temp;

	if (!alst || !del)
		return ;
	head = *alst;
	while (head)
	{
		(*del)(head->content, head->content_size);
		temp = head->next;
		free(head);
		head = temp;
	}
	*alst = NULL;
}
