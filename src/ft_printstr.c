/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:37 by ksadiku           #+#    #+#             */
/*   Updated: 2023/03/03 14:24:00 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printstr_helper(t_data *data, char *str)
{
	int		width;

	width = 0;
	if (str == NULL) {
		data->null_c = true;
		width += write(1, "(null)", 6);
	}
	else if (*str == '\0' || str == (char *)0)
	{
		while (data->flags.is_digit && data->length-- > 0)
			width += write(1, &data->flags.padc, 1);
	}
	return (width);
}

int	ft_flag_print(t_data *data, char *str, int (*putc)(char))
{
	int		width = 0;
	int		n = 0;
	char	*head;

	if (data->flags.prec == -1)
		data->flags.prec = 0x7fffffff;
	if (data->flags.prec == 0x7fffffff && !data->flags.ladjust && str == NULL)
		return 0;
	if (data->length > 0 && !data->flags.ladjust) 
	{
		head = str;
		while ((*str++ != '\0' && n < data->flags.prec))
			n++;
		str = head;
		while (n < data->length) {
			width += (*putc)(' ');
			n++;
		}
	}
	n = 0;
	while (str == NULL || *str != '\0') {
		if (n >= data->flags.prec || (data->flags.num > 0 && n > data->flags.num))
			break ;
		n++;
		width += (*putc)(*str++);
	}
	if (n < data->flags.num && data->flags.ladjust) {
		while (n < data->length) {
			width += (*putc)(data->flags.padc);
			n++;
		}
	}
	return (width);
}

int	ft_printstr(t_data *data, char *str)
{
	int		width;

	width = 0;
	data->length = data->flags.num;
	if (str == NULL || *str)
	width += ft_printstr_helper(data, str);
	width += ft_flag_print(data, str, ft_putc);
	return (width);
}
