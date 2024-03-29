/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:50 by ksadiku           #+#    #+#             */
/*   Updated: 2023/03/03 16:48:03 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init_add(t_data *data)
{
	data->capitals = 0;
	data->bits = 0;
	data->null_c = false;
	data->ptr_addr = false;
	data->its_prec = false;
	data->sign_c = 0;
	data->length = 0;
	data->base = 0;
	data->pads_used = 0;
	data->prefix = NULL;
	data->build = NULL;
	data->flags.num = 0;
	data->flags.prec = -1;
	data->flags.add_sign = false;
	data->flags.ladjust = false;
	data->flags.altfmt = false;
	data->flags.is_digit = false;
	data->flags.plus_sign = 0;
	data->flags.padc = ' ';
}

static int	ft_specifier2(t_data *ap, const char *format, int i)
{
	i += ft_flags(ap, (char *)&format[i]);
	i += ft_padwidth(ap, (char *)&format[i]);
	i += ft_modifier(ap, (char *)&format[i]);
	ft_hexchecker(ap, format, i);
	return (i);
}

/* %i makes hex, oxtal to and integer value otherwise its same as decimal */
int	ft_specifier(t_data *ap, const char *format, int i)
{
	i = ft_specifier2(ap, format, i);
	if (format[i] == 'c')
		ap->width += ft_printchr(ap, va_arg(ap->args, int), ft_putc);
	else if (format[i] == 's')
		ap->width += ft_printstr(ap, va_arg(ap->args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		ap->width += ft_print_int(ap, va_arg(ap->args, long));
	else if (format[i] == 'p')
		ap->width += ft_print_u(ap, va_arg(ap->args, unsigned long long), 16);
	else if (format[i] == 'u')
		ap->width += ft_print_u(ap, va_arg(ap->args, unsigned int), 10);
	else if (format[i] == 'x' || format[i] == 'X')
		ap->width += ft_print_u(ap, va_arg(ap->args, unsigned long), 16);
	else if (format[i] == 'o')
		ap->width += ft_print_u(ap, va_arg(ap->args, unsigned int), 8);
	else if (format[i] == '%')
		ap->width += ft_printchr(ap, '%', ft_putc);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	t_data	data;

	i = 0;
	va_start(data.args, format);
	data.width = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			data.width += write(1, "%%", 1);
			i++;
		}
		else if (format[i] == '%')
		{
			ft_init_add(&data);
			i = ft_specifier(&data, format, i + 1);
		}
		else
			data.width += write(1, &format[i], 1);
		i++;
	}
	va_end(data.args);
	return (data.width);
}
