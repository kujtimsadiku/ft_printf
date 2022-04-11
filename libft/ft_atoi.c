/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:50:29 by ksadiku           #+#    #+#             */
/*   Updated: 2021/12/02 12:33:26 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_ws(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	return (i);
}

static	int	ft_atoi_neg(char *num, int i, int ttrue, int tfalse)
{
	if (num[i] == '-')
		return (tfalse);
	else
		return (ttrue);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				n_p;

	i = ft_check_ws(str);
	n_p = ft_atoi_neg((char *)str, i, 1, -1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 9223372036854775807)
		{
			if (n_p == 1)
				return (-1);
			else
				return (0);
		}
		i++;
	}
	return (res * n_p);
}
