/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:44 by ksadiku           #+#    #+#             */
/*   Updated: 2023/02/20 16:04:33 by ksadiku          ###   ########.fr       */
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

int	ft_itsptr(t_data *data, unsigned long long u)
{
	if (u == 0 && data->flags.altfmt && data->ptr_addr)
		return (write(1, "0x0", 3));
	else
		return (write(1, "0", 1));
}

int	ft_print_u(t_data *data, unsigned long long u, int base)
{
	static char	digits[MAXBUF];
	char		*build;
	int			length;

	ft_strcpy(digits, "0123456789abcdef0123456789ABCDEF");
	build = &digits[MAXBUF - 1];
	length = 0;
	if (u == 0 && data->flags.altfmt)
		return (ft_itsptr(data, u));
	ft_typecast_u(data, &u);
	while (u != 0)
	{
		*build-- = digits[u % base + data->capitals];
		u /= base;
	}
	build++;
	length += ft_printstr(data, &(*build));
	return (length);
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
	char	*numstr;
	int		length;

	ft_typecast(data, &num);
	numstr = ft_itoa(num);
	if (num < 0)
	{
		if (data->flags.plus_sign != 0)
			data->flags.plus_sign = 0;
	}
	length = ft_printstr(data, numstr);
	ft_free(numstr, length);
	return (length);
}
