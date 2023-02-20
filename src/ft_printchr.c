/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:25 by ksadiku           #+#    #+#             */
/*   Updated: 2023/02/20 16:02:54 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printpads(unsigned int n, char c)
{
	int		len;

	len = 0;
	while (n)
	{
		len += write(1, &c, 1);
		n--;
	}
	return (len);
}

int	ft_printchr(t_data *data, int c)
{
	int		len;

	len = 0;
	if (data->flags.ladjust)
	{
		len += write(1, &c, 1);
		len += ft_printpads(data->flags.num - 1, data->flags.padc);
	}
	else if (data->flags.padc == '0')
	{
		len += ft_printpads(data->flags.num - 1, data->flags.padc);
		len += write(1, &c, 1);
	}
	else if (data->flags.is_digit)
	{
		len += ft_printpads(data->flags.num - 1, data->flags.padc);
		len += write(1, &c, 1);
	}
	else
		len += write(1, &c, 1);
	return (len);
}
