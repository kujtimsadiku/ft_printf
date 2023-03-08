/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:50:34 by ksadiku           #+#    #+#             */
/*   Updated: 2023/03/08 12:01:25 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_prefix(t_data *data)
{
	if ((data->base == 8 && data->flags.altfmt) || (data->base == 8 && data->its_prec))
		data->prefix = "0";
	else if (data->base == 16 && data->flags.altfmt && data->capitals == 0)
		data->prefix = "0x";
	else if (data->base == 16 && data->flags.altfmt && data->capitals == 16)
		data->prefix = "0X";
}

int	ft_printint(t_data *data, char *num, int (*putc)(char))
{
	int	length;

	length = 0;
	data->length = data->flags.num > ?
	if (data->sign_c)
		data->length--;
	/*	
		If prec is bigger than num then we forget about the num but if num
		is bigger than prec and prec is longer than string length then we pad '0'
		as much as prec - strlen, and the rest of the sum will be 
		num - ((prec - string length) + string length) if the sum is 0
		then we dont need to print pads. 
	*/
	if (!data->flags.ladjust)
		while (data->length-- > 0)
			length += (*putc)(' ');
	if (data->sign_c)
		length += (*putc)(data->sign_c);
	while (*num)
			length += (*putc)(*num++);
	if (data->flags.ladjust)
		while (data->length-- > 0)
			length += (*putc)(' ');
	return (length);
}

int	ft_printnumber(t_data *data, char *num, int (*putc)(char))
{
	int	length;

	length = 0;
	ft_prefix(data);
	if (data->flags.num > data->flags.prec)
		data->length = data->flags.num - ft_strlen(num);
	else
		data->length = data->flags.prec - ft_strlen(num);
	if (num == NULL && data->flags.altfmt)
		length += write(1, "0x", 2);
	if (data->prefix)
		data->length -= ft_strlen(data->prefix);
	if (data->sign_c)
		data->length--;
	if (data->flags.padc == ' ' && !data->flags.ladjust)
		while (data->length-- > 0)
			length += (*putc)(' ');
	if (data->sign_c)
		length += (*putc)(data->sign_c);
	if (data->prefix)
		while (*data->prefix)
			length += (*putc)(*data->prefix++);
	if (data->flags.padc == '0')
		while (data->length-- > 0)
			length += (*putc)('0');
	while (*num)
		length += (*putc)(*num++);
	if (data->flags.ladjust)
		while (data->length-- > 0)
			length += (*putc)(' ');
	return (length);
}