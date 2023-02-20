/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:37 by ksadiku           #+#    #+#             */
/*   Updated: 2023/02/20 16:06:32 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puts(t_data *data, char *str)
{
	int	width;

	width = 0;
	if (data->flags.altfmt)
	{
		if (data->capitals == 16)
			width += write(1, "0X", 2);
		else
			width += write(1, "0x", 2);
	}
	width += write(1, str, ft_strlen(str));
	return (width);
}

int	ft_printstr_helper(t_data *data, char *str)
{
	int		width;

	width = 0;
	if (str == NULL && data->flags.altfmt)
		return (write(1, "0x", 2));
	if (str == NULL)
	{
		data->null_c = true;
		width += write(1, "(null)", 6);
	}
	else if (*str == '\0')
	{
		if (data->flags.is_digit)
			width += ft_printpads(data->flags.num, data->flags.padc);
	}
	return (width);
}

static int	ft_printstr2(t_data *data, char *str)
{
	int		width;

	width = 0;
	if (data->flags.is_digit)
	{
		width += ft_printpads(data->flags.num - \
						ft_strlen(str), data->flags.padc);
		width += ft_puts(data, str);
	}
	else if (data->flags.plus_sign != 0)
	{
		width += ft_printpads(1, data->flags.plus_sign);
		width += ft_puts(data, str);
	}
	else
		width += ft_puts(data, str);
	return (width);
}

int	ft_printstr(t_data *data, char *str)
{
	int		width;

	width = ft_printstr_helper(data, str);
	if (data->null_c)
		return (width);
	if (data->flags.ladjust)
	{
		width += ft_puts(data, str);
		width += ft_printpads(data->flags.num - \
						ft_strlen(str), data->flags.padc);
	}
	else if (data->flags.padc == '0')
	{
		width += ft_printpads(data->flags.num - \
						ft_strlen(str), data->flags.padc);
		width += ft_puts(data, str);
	}
	else
		width += ft_printstr2(data, str);
	return (width);
}
