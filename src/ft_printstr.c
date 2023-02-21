/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:37 by ksadiku           #+#    #+#             */
/*   Updated: 2023/02/21 16:02:34 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void ft_prefix(t_data *data)
{
	if (data->base == 8 && data->flags.altfmt || data->base == 8 && data->flags.altfmt)
		data->prefix = "0";
	else if (data->base == 16 && data->flags.altfmt && data->capitals == 0)
		data->prefix = "0x";
	else if (data->base == 16 && data->flags.altfmt && data->capitals == 16)
		data->prefix = "0X";
}

int	ft_puts(t_data *data, char *str)
{
	int width;
	int	i;

	width = 0;
	i = -1;
	while (str[++i] != '\0')
		width += write(1, &str[i], 1);
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
	else if (*str == '\0' || str == (char *)0)
	{
		if (data->flags.is_digit)
			width += ft_printpads(data);
	}
	return (width);
}

int	ft_flag_print(t_data *data, char *str)
{
	int	width;
	int	i;

	width = 0;
	i = -1;
	if (data->flags.padc == ' ' && !data->flags.ladjust)
		width += ft_printpads(data);
	if (data->c)
		width += write(1, &data->c, 1);
	if (data->prefix)
		while (*data->prefix)
			width += write(1, (&(*data->prefix++)), 1);
	if (data->flags.padc == '0')
		width += ft_printpads(data);
	width += ft_puts(data, str);
	if (data->flags.ladjust && data->length - ft_strlen(str) >= 0)
		width += ft_printpads(data);
	return (width);                 
}

int	ft_printstr(t_data *data, char *str)
{
	int		width;

	width = ft_printstr_helper(data, str);
	ft_prefix(data);
	if (str == NULL || str == (char *)0 || *str == '\0')
		return (width);
	data->length += data->flags.num - ft_strlen(str);
	if (data->prefix)
		data->length -= ft_strlen(data->prefix);
	if (data->c)
		data->length -= 1;
	width += ft_flag_print(data, str);
	// if (data->flags.plus_sign)
	// 	data->length -= 1;
	// if (data->flags.plus_sign)
	// 	width += write(1, &(data->flags.plus_sign), 1);
	// if (!data->flags.ladjust && data->length > 0)
	// 	width += ft_printpads(data);
	// width += ft_puts(data, str);
	// if (data->flags.ladjust && data->length > 0)
	// 	width += ft_printpads(data);
	return (width);
}
