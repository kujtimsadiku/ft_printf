/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:44 by ksadiku           #+#    #+#             */
/*   Updated: 2023/03/03 18:14:24 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_typecast_u(t_data *data, unsigned long long *num)
{
	if (data->bits == 8)
		*num = (unsigned char)*num;
	else if (data->bits == 64)
		*num = (unsigned long long)*num;
	else if (data->bits == 16)
		*num = (unsigned short)*num;
	else if (data->bits == 32)
		*num = (unsigned long)*num;
	else if (data->ptr_addr)
		return ;
	else
		*num = (unsigned int)*num;
}

	/*  0, true, true, not true */
int	ft_itsptr(t_data *data, unsigned long long u)
{
	int	n = 0;

	if (u == 0 && data->flags.prec <= 0 && data->its_prec) {
		if (data->flags.padc)
			n = ft_printnumber(data, "", ft_putc);
		return (n);
	}
	if (u == 0 && data->flags.altfmt && data->ptr_addr)
		return (write(1, "0x0", 3));
	else
		return (write(1, "0", 1));
}

int	ft_print_u(t_data *data, unsigned long long u, int base)
{
	static char	digits[MAXBUF];

	ft_strncpy(digits, "0123456789abcdef0123456789ABCDEF", 32);
	data->build = &digits[MAXBUF - 1];
	ft_typecast_u(data, &u);
	if (u == 0 && base != 8)
		return (ft_itsptr(data, u));
	else if (u == 0 && base == 8 && data->its_prec && !data->flags.altfmt)
		return (ft_printnumber(data, "", ft_putc));
	else if (u == 0 && base == 8)
		return (write(1, "0", 1));
	if (base == 8 && data->flags.prec > 0) {
		if (data->flags.num > data->flags.prec && data->flags.ladjust)
			data->flags.padc = ' ';
		else
			data->flags.padc = '0';
	}
	while (u != 0)
	{
		*data->build-- = digits[u % base + data->capitals];
		u /= base;
	}
	data->build++;
	data->base = base;
	return (ft_printnumber(data, data->build, ft_putc));
}

void	ft_typecast(t_data *data, long long *num)
{
	if (data->bits == 8)
		*num = (char)*num;
	else if (data->bits == 64)
		*num = (long long)*num;
	else if (data->bits == 16)
		*num = (short)*num;
	else if (data->bits == 32)
		*num = (long)*num;
	else
		*num = (int)*num;
}

int	ft_print_int(t_data *data, long long num)
{
	static char		digits[MAXBUF];
	unsigned long long		u;

	ft_typecast(data, &num);
	ft_strncpy(digits, "0123456789abcdef0123456789ABCDEF", 32);
	data->build = &digits[MAXBUF - 1];
	u = num;
	if (data->flags.num > data->flags.prec && data->flags.ladjust)
		data->flags.padc = ' ';
	else if (data->flags.num < data->flags.prec)
		data->flags.padc = '0';
	if (num == 0)
		*data->build-- = digits[u % 10];
	if (num < 0) {
		u = -num;
		data->sign_c = '-';
	}
	else
		data->sign_c = data->flags.plus_sign;
	while (u != 0) {
		*data->build-- = digits[u % 10];
		u /= 10;
	}
	if ((int)ft_strlen(data->build) < data->flags.prec)
		*(data->build--) = '0';
	data->build++;
	return (ft_printint(data, data->build, ft_putc));
}
