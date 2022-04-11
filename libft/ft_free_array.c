/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:54:48 by ksadiku           #+#    #+#             */
/*   Updated: 2022/03/22 11:54:50 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_array(void **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_free(arr[i], ft_strlen(arr[i]));
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}
