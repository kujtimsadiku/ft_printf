/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <kuite.s@hotmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:58:03 by ksadiku           #+#    #+#             */
/*   Updated: 2023/02/20 16:25:55 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_modifier(t_data *data, char *str)
{
	if (!ft_strncmp(str, "ll", 2) || !ft_strncmp(str, "hh", 2))
	{
		if (!ft_strncmp(str, "ll", 2))
			data->bits = 64;
		else
			data->bits = 8;
		return (2);
	}
	else if (*str == 'h')
		data->bits = 16;
	else if (*str == 'l')
		data->bits = 32;
	else if (*str == 'L')
		data->bits = 64;
	else
		return (0);
	return (1);
}

int	ft_flags(t_data *data, char *str)
{
	int	i;

	i = 0;
	data->c = *str;
	while (true)
	{
		if (data->c == '#')
			data->flags.altfmt = true;
		else if (data->c == '-')
			data->flags.ladjust = true;
		else if (data->c == '+')
			data->flags.plus_sign = '+';
		else if (data->c == ' ')
		{
			if (data->flags.plus_sign == 0)
				data->flags.plus_sign = ' ';
		}
		else
			break ;
		i++;
		data->c = *(++str);
	}
	return (i);
}

int	ft_padwidth(t_data *data, char *str)
{
	int		i;

	i = 0;
	if (*str == '0')
	{
		if (data->flags.ladjust)
			data->flags.padc = ' ';
		else
			data->flags.padc = '0';
		i++;
		str++;
	}
	if (ft_isdigit(*str))
	{
		data->flags.is_digit = true;
		while (ft_isdigit(*str))
		{
			data->flags.num = 10 * data->flags.num + (*str - '0');
			data->c = *str++;
			i++;
		}
	}
	return (i);
}

int	ft_precision(t_data *data, char *p)
{
	char	c;
	int		i;

	c = *p;
	i = 0;
	if (c == '.')
	{
		while (ft_isdigit(*p))
		{
			data->length = 10 * data->flags.num + (c - '0');
			c = *++p;
			i++;
		}
	}
	return (i);
}

void	ft_hexchecker(t_data *ap, const char *format, int i)
{
	if (format[i] == 'x')
		ap->capitals = 0;
	else if (format[i] == 'X')
		ap->capitals = 16;
	else if (format[i] == 'p')
	{
		ap->flags.altfmt = true;
		ap->ptr_addr = true;
	}
	else if (format[i] == 'u')
		ap->flags.plus_sign = 0;
	else if (format[i] == 'o')
		ap->flags.plus_sign = 0;
	else
		return ;
	ap->flags.plus_sign = 0;
}