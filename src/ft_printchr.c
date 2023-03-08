/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:25 by ksadiku           #+#    #+#             */
/*   Updated: 2023/03/03 14:32:34 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putc(char c)
{
	return (write(1, &c, 1));
}

int	ft_printpads(t_data *data, int c)
{
	int		len;

	len = 0;
	if (c == '%') {
		while (data->length-- > 1)
			len += write(1, &(data->flags.padc), 1);
	}
	else {
		while (data->length-- > 0)
			len += write(1, &(data->flags.padc), 1);
	}
	return (len);
}

int	ft_printchr(t_data *data, int c, int (*putc)(char))
{
	int	len;

	len = 0;
	if (c != '%')
		data->length = data->flags.num - 1;
	else
		data->length = data->flags.num;
	if (!data->flags.ladjust && data->length > 0)
		len += ft_printpads(data, c);
	if (c != '%')
		len += (*putc)(c);
	else
		len += (*putc)('%');
	if (data->flags.ladjust && data->length > 0)
		len += ft_printpads(data, c);
	return (len);
}
