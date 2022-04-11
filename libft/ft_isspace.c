/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:17:51 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/02 14:00:16 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if ((unsigned char)c == ' ' || (unsigned char)c == '\n'
		|| (unsigned char)c == '\t' || (unsigned char)c == '\v'
		|| (unsigned char)c == '\r' || (unsigned char)c == '\f')
		return (1);
	return (0);
}
